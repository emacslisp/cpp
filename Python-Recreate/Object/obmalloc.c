/*
 * obmalloc.c
 *
 *  Created on: 14Jun.,2018
 *      Author: di.wu
 */
#include "Python.h"


/* Defined in tracemalloc.c */
extern void _PyMem_DumpTraceback(int fd, const void *ptr);


/* Python's malloc wrappers (see pymem.h) */

#undef  uint
#define uint    unsigned int    /* assuming >= 16 bits */

/* Forward declaration */
static void* _PyMem_DebugRawMalloc(void *ctx, size_t size);
static void* _PyMem_DebugRawCalloc(void *ctx, size_t nelem, size_t elsize);
static void* _PyMem_DebugRawRealloc(void *ctx, void *ptr, size_t size);
static void _PyMem_DebugRawFree(void *ctx, void *p);

static void* _PyMem_DebugMalloc(void *ctx, size_t size);
static void* _PyMem_DebugCalloc(void *ctx, size_t nelem, size_t elsize);
static void* _PyMem_DebugRealloc(void *ctx, void *ptr, size_t size);
static void _PyMem_DebugFree(void *ctx, void *p);

static void _PyObject_DebugDumpAddress(const void *p);
static void _PyMem_DebugCheckAddress(char api_id, const void *p);

#if defined(__has_feature)  /* Clang */
 #if __has_feature(address_sanitizer)  /* is ASAN enabled? */
  #define ATTRIBUTE_NO_ADDRESS_SAFETY_ANALYSIS \
        __attribute__((no_address_safety_analysis))
 #else
  #define ATTRIBUTE_NO_ADDRESS_SAFETY_ANALYSIS
 #endif
#else
 #if defined(__SANITIZE_ADDRESS__)  /* GCC 4.8.x, is ASAN enabled? */
  #define ATTRIBUTE_NO_ADDRESS_SAFETY_ANALYSIS \
        __attribute__((no_address_safety_analysis))
 #else
  #define ATTRIBUTE_NO_ADDRESS_SAFETY_ANALYSIS
 #endif
#endif

#ifdef WITH_PYMALLOC

#ifdef MS_WINDOWS
#  include <windows.h>
#elif defined(HAVE_MMAP)
#  include <sys/mman.h>
#  ifdef MAP_ANONYMOUS
#    define ARENAS_USE_MMAP
#  endif
#endif

/* Forward declaration */
static void* _PyObject_Malloc(void *ctx, size_t size);
static void* _PyObject_Calloc(void *ctx, size_t nelem, size_t elsize);
static void _PyObject_Free(void *ctx, void *p);
static void* _PyObject_Realloc(void *ctx, void *ptr, size_t size);
#endif


static void *
_PyMem_RawMalloc(void *ctx, size_t size)
{
    /* PyMem_RawMalloc(0) means malloc(1). Some systems would return NULL
       for malloc(0), which would be treated as an error. Some platforms would
       return a pointer with no memory behind it, which would break pymalloc.
       To solve these problems, allocate an extra byte. */
    if (size == 0)
        size = 1;
    return malloc(size);
}


static void *
_PyMem_RawCalloc(void *ctx, size_t nelem, size_t elsize)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    /* PyMem_RawCalloc(0, 0) means calloc(1, 1). Some systems would return NULL
       for calloc(0, 0), which would be treated as an error. Some platforms
       would return a pointer with no memory behind it, which would break
       pymalloc.  To solve these problems, allocate an extra byte. */
    if (nelem == 0 || elsize == 0) {
        nelem = 1;
        elsize = 1;
    }
    return calloc(nelem, elsize);
}

static void *
_PyMem_RawRealloc(void *ctx, void *ptr, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    if (size == 0)
        size = 1;
    return realloc(ptr, size);
}

static void
_PyMem_RawFree(void *ctx, void *ptr)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    free(ptr);
}


#ifdef MS_WINDOWS
static void *
_PyObject_ArenaVirtualAlloc(void *ctx, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    return VirtualAlloc(NULL, size,
                        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

static void
_PyObject_ArenaVirtualFree(void *ctx, void *ptr, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    VirtualFree(ptr, 0, MEM_RELEASE);
}

#elif defined(ARENAS_USE_MMAP)
static void *
_PyObject_ArenaMmap(void *ctx, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    void *ptr;
    ptr = mmap(NULL, size, PROT_READ|PROT_WRITE,
               MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
        return NULL;
    assert(ptr != NULL);
    return ptr;
}

static void
_PyObject_ArenaMunmap(void *ctx, void *ptr, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    munmap(ptr, size);
}

#else
static void *
_PyObject_ArenaMalloc(void *ctx, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    return malloc(size);
}

static void
_PyObject_ArenaFree(void *ctx, void *ptr, size_t size)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    free(ptr);
}
#endif



#define PYRAW_FUNCS _PyMem_RawMalloc, _PyMem_RawCalloc, _PyMem_RawRealloc, _PyMem_RawFree
#ifdef WITH_PYMALLOC
#  define PYOBJ_FUNCS _PyObject_Malloc, _PyObject_Calloc, _PyObject_Realloc, _PyObject_Free
#else
#  define PYOBJ_FUNCS PYRAW_FUNCS
#endif
#define PYMEM_FUNCS PYOBJ_FUNCS

typedef struct {
    /* We tag each block with an API ID in order to tag API violations */
    char api_id;
    PyMemAllocatorEx alloc;
} debug_alloc_api_t;
static struct {
    debug_alloc_api_t raw;
    debug_alloc_api_t mem;
    debug_alloc_api_t obj;
} _PyMem_Debug = {
    {'r', {NULL, PYRAW_FUNCS}},
    {'m', {NULL, PYMEM_FUNCS}},
    {'o', {NULL, PYOBJ_FUNCS}}
    };

#define PYRAWDBG_FUNCS \
    _PyMem_DebugRawMalloc, _PyMem_DebugRawCalloc, _PyMem_DebugRawRealloc, _PyMem_DebugRawFree
#define PYDBG_FUNCS \
    _PyMem_DebugMalloc, _PyMem_DebugCalloc, _PyMem_DebugRealloc, _PyMem_DebugFree

static PyMemAllocatorEx _PyMem_Raw = {
#ifdef Py_DEBUG
    &_PyMem_Debug.raw, PYRAWDBG_FUNCS
#else
    NULL, PYRAW_FUNCS
#endif
    };

static PyMemAllocatorEx _PyMem = {
#ifdef Py_DEBUG
    &_PyMem_Debug.mem, PYDBG_FUNCS
#else
    NULL, PYMEM_FUNCS
#endif
    };

static PyMemAllocatorEx _PyObject = {
#ifdef Py_DEBUG
    &_PyMem_Debug.obj, PYDBG_FUNCS
#else
    NULL, PYOBJ_FUNCS
#endif
    };


int
_PyMem_SetupAllocators(const char *opt)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    if (opt == NULL || *opt == '\0') {
        /* PYTHONMALLOC is empty or is not set or ignored (-E/-I command line
           options): use default allocators */
#ifdef Py_DEBUG
#  ifdef WITH_PYMALLOC
        opt = "pymalloc_debug";
#  else
        opt = "malloc_debug";
#  endif
#else
   /* !Py_DEBUG */
#  ifdef WITH_PYMALLOC
        opt = "pymalloc";
#  else
        opt = "malloc";
#  endif
#endif
    }

    if (strcmp(opt, "debug") == 0) {
        PyMem_SetupDebugHooks();
    }
    else if (strcmp(opt, "malloc") == 0 || strcmp(opt, "malloc_debug") == 0)
    {
        PyMemAllocatorEx alloc = {NULL, PYRAW_FUNCS};

        PyMem_SetAllocator(PYMEM_DOMAIN_RAW, &alloc);
        PyMem_SetAllocator(PYMEM_DOMAIN_MEM, &alloc);
        PyMem_SetAllocator(PYMEM_DOMAIN_OBJ, &alloc);

        if (strcmp(opt, "malloc_debug") == 0)
            PyMem_SetupDebugHooks();
    }
#ifdef WITH_PYMALLOC
    else if (strcmp(opt, "pymalloc") == 0
             || strcmp(opt, "pymalloc_debug") == 0)
    {
        PyMemAllocatorEx raw_alloc = {NULL, PYRAW_FUNCS};
        PyMemAllocatorEx mem_alloc = {NULL, PYMEM_FUNCS};
        PyMemAllocatorEx obj_alloc = {NULL, PYOBJ_FUNCS};

        PyMem_SetAllocator(PYMEM_DOMAIN_RAW, &raw_alloc);
        PyMem_SetAllocator(PYMEM_DOMAIN_MEM, &mem_alloc);
        PyMem_SetAllocator(PYMEM_DOMAIN_OBJ, &obj_alloc);

        if (strcmp(opt, "pymalloc_debug") == 0)
            PyMem_SetupDebugHooks();
    }
#endif
    else {
        /* unknown allocator */
        return -1;
    }
    return 0;
}
