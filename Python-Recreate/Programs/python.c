/*
 * python.c
 *
 *  Created on: 14Jun.,2018
 *      Author: di.wu
 */
#include "Python.h"
#include <locale.h>

int main(int argc, char **argv)
{
    wchar_t **argv_copy;
    /* We need a second copy, as Python might modify the first one. */
    wchar_t **argv_copy2;
    int i, res;
    char *oldloc;

    /* Force malloc() allocator to bootstrap Python */
    (void)_PyMem_SetupAllocators("malloc");

    argv_copy = (wchar_t **)PyMem_RawMalloc(sizeof(wchar_t*) * (argc+1));
    argv_copy2 = (wchar_t **)PyMem_RawMalloc(sizeof(wchar_t*) * (argc+1));
    if (!argv_copy || !argv_copy2) {
 	   fprintf(stderr, "out of memory\n");
	   return 1;
    }

    oldloc = _PyMem_RawStrdup(setlocale(LC_ALL, NULL));
        if (!oldloc) {
            fprintf(stderr, "out of memory\n");
            return 1;
        }

        setlocale(LC_ALL, "");
        /*for (i = 0; i < argc; i++) {
            argv_copy[i] = Py_DecodeLocale(argv[i], NULL);
            if (!argv_copy[i]) {
                PyMem_RawFree(oldloc);
                fprintf(stderr, "Fatal Python error: "
                                "unable to decode the command line argument #%i\n",
                                i + 1);
                return 1;
            }
            argv_copy2[i] = argv_copy[i];
        }
        argv_copy2[argc] = argv_copy[argc] = NULL;

        setlocale(LC_ALL, oldloc);
        PyMem_RawFree(oldloc);*/

// start of Py_Main();

    // printf("main in different folder!!!");
}
