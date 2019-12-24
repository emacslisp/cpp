/*
 * pgenmain.c
 *
 *  Created on: 24 Dec 2019
 *      Author: wudi
 */


/* Parser generator main program */

/* This expects a filename containing the grammar as argv[1] (UNIX)
   or asks the console for such a file name (THINK C).
   It writes its output on two files in the current directory:
   - "graminit.c" gets the grammar as a bunch of initialized data
   - "graminit.h" gets the grammar's non-terminals as #defines.
   Error messages and status info during the generation process are
   written to stdout, or sometimes to stderr. */

/* XXX TO DO:
   - check for duplicate definitions of names (instead of fatal err)
*/

#define PGEN

#include "Python.h"
#include "pgenheaders.h"
#include "grammar.h"
#include "node.h"
#include "parsetok.h"
#include "pgen.h"

int Py_DebugFlag;
int Py_VerboseFlag;
int Py_IgnoreEnvironmentFlag;

/* Forward */
grammar *getgrammar(const char *filename);

void Py_Exit(int) _Py_NO_RETURN;

void
Py_Exit(int sts)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    exit(sts);
}

#ifdef WITH_THREAD
/* Needed by obmalloc.c */
int PyGILState_Check(void)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__); return 1; }
#endif

void _PyMem_DumpTraceback(int fd, const void *ptr)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);}


/* Can't happen in pgen */
PyObject*
PyErr_Occurred()
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    return 0;
}

void
Py_FatalError(const char *msg)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    fprintf(stderr, "pgen: FATAL ERROR: %s\n", msg);
    Py_Exit(1);
}

/* No-nonsense my_readline() for tokenizer.c */

char *
PyOS_Readline(FILE *sys_stdin, FILE *sys_stdout, const char *prompt)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    size_t n = 1000;
    char *p = (char *)PyMem_MALLOC(n);
    char *q;
    if (p == NULL)
        return NULL;
    fprintf(stderr, "%s", prompt);
    q = fgets(p, n, sys_stdin);
    if (q == NULL) {
        *p = '\0';
        return p;
    }
    n = strlen(p);
    if (n > 0 && p[n-1] != '\n')
        p[n-1] = '\n';
    return (char *)PyMem_REALLOC(p, n+1);
}

/* No-nonsense fgets */
char *
Py_UniversalNewlineFgets(char *buf, int n, FILE *stream, PyObject *fobj)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    return fgets(buf, n, stream);
}


#include <stdarg.h>

void
PySys_WriteStderr(const char *format, ...)
{printf("%s %s %d\n",__FUNCTION__,__FILE__,__LINE__);
    va_list va;

    va_start(va, format);
    vfprintf(stderr, format, va);
    va_end(va);
}



