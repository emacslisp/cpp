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

void reverArray(int* array, int i,int j) {
    while(i<j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
        i++;
        j--;
    }
}

int minArrayIndex(int array[], int i, int j) {
    int min = i;
    while(i<j) {
        if(array[i] < array[min]) {
            min = i;
        }
        i++;
    }
    return min;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("Reversort_A_QR_20221.in", "r", stdin);
    freopen("Reversort_A_QR_20221.out", "w", stdout);
#endif

    int N, T;
    scanf("%d\n", &T);
    int array[100];
    for (int o = 1; o <= T; o++)
    {
        scanf("%d\n", &N);
        memset(array, 0, 100*sizeof(int));

        for(int u = 0; u<N; u++) {
            scanf("%d\n", &array[u]);
        }
        
        int result = 0;

        for(int i=0;i<N-1;i++) {
            int min = minArrayIndex(array, i, N);
            result += (min - i + 1);
            reverArray(array, i, min);
        }

        cout << "Case #" << o <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}