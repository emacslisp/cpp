#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("Vestigium_CodeJam2020_A.in", "r", stdin);
    freopen("Vestigium_CodeJam2020_A.out", "w", stdout);
#endif

    int N, T;
    scanf("%d\n", &N);

    int array[100][100];

    for (int i = 0; i < N; i++)
    {
        scanf("%d\n", &T);

        memset(array, 0, 100*100*sizeof(int));

        for (int m = 0; m < T; m++)
        {
            for (int n = 0; n < T; n++)
            {
                scanf("%d", &array[m][n]);
            }
        }

        int sum = 0;
        int rCount = 0;
        int cCount = 0;
        map<int, int> r;
        map<int, int> c;
        bool rDup,cDup;
        for (int m = 0; m < T; m++)
        {
            r.clear();
            rDup = false;
            for (int n = 0; n < T; n++)
            {
                if(m==n) sum+=array[m][n];
                if(r.count(array[m][n]) > 0) {
                    rDup = true;
                } else {
                    r[array[m][n]] = 1;
                }
            }

            if(rDup) {
                rCount++;
            }
        }

        for (int n = 0; n < T; n++)
        {
            c.clear();
            cDup = false;
            for (int m = 0; m < T; m++)
            {
                if(c.count(array[m][n]) > 0) {
                    cDup = true;
                } else {
                    c[array[m][n]] = 1;
                }
            }

            if(cDup) {
                cCount++;
            }
        }

        printf("Case #%d: %d %d %d\n", (i+1), sum, rCount, cCount);
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}