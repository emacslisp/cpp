#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#define FILEIO
#define Max(a, b) a > b ? a : b
int c[10001];


int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("SelfNumbers_poj1316.in", "r", stdin);
    freopen("SelfNumbers_poj1316.out", "w", stdout);
#endif

    for(int i=1;i<=10000;i++) {
        c[i] = 1;
    }

    for(int i=1;i<=10000;i++) {
        int p = i;
        int sum = i;
        while(p > 0) {
             sum += p%10;
             p = p/10;
        }
        if(sum <= 10000) {
            c[sum] = 0;
        }
    }

    for(int i=1;i<=10000;i++) {
        if(c[i] == 1) {
            printf("%d\n", i);
        }
    }
    
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}