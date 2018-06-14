/*
 * obmalloc.c
 *
 *  Created on: 14Jun.,2018
 *      Author: di.wu
 */


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
