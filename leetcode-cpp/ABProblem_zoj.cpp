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
    freopen("ABProblem_zoj.in", "r", stdin);
    freopen("ABProblem_zoj.out", "w", stdout);
#endif

    int A, B;
    while(scanf("%d %d", &A, &B) != EOF) {
        cout << A+B << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}