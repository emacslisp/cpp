#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#define FILEIO
#define Max(a, b) a > b ? a : b


int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("ABProblem_poj1000.in", "r", stdin);
    freopen("ABProblem_poj1000.out", "w", stdout);
#endif

    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}