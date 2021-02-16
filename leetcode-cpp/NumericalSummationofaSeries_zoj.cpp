#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#define Max(a, b) a > b ? a : b

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("NumericalSummationofaSeries_zoj.in", "r", stdin);
    freopen("NumericalSummationofaSeries_zoj.out", "w", stdout);
#endif
    double sum;
    for(double i=0;i<=2;i+=0.001) {
        sum = 0;
        for(int k=1;k<10000;k++) {
            sum += (1.0/(k*(k+1)*(k+i)));
        }

        sum = (1-i) * sum + (1.0 - i)/(2* 10000 * 10000) + 1.0;
        printf("%5.3f %16.12f\n", i, sum);
    }
    
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}