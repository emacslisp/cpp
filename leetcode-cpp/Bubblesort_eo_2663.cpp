#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 
int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("Bubblesort_eo_2663.in", "r", stdin);
    freopen("Bubblesort_eo_2663.out", "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);

    int array[1001];
    memset(array, 0, 1001 * sizeof(int));

    for (int x=0;x<N;x++) {
        scanf("%d", &array[x]);
    }

    int count = 0;
    for(int i = 0; i< N;i++) {
        for(int j=0;j<N-1;j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                count++;
            }
        }
    }
    cout << count << endl;

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}