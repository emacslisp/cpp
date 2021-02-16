#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("Simpleproblem_eo_1.in", "r", stdin);
    freopen("Simpleproblem_eo_1.out", "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);
    
    cout << (N-N%10)/10 << " " << N%10 << endl;
    
#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}