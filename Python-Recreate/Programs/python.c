/*
 * python.c
 *
 *  Created on: 14Jun.,2018
 *      Author: di.wu
 */
#include "Python.h"

int main()
{
    wchar_t **argv_copy;
    /* We need a second copy, as Python might modify the first one. */
    wchar_t **argv_copy2;
    int i, res;
    char *oldloc;

    /* Force malloc() allocator to bootstrap Python */
    // (void)_PyMem_SetupAllocators("malloc");
    printf("main in different folder!!!");
}
