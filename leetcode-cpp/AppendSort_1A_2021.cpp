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
#define ll long long 

using namespace std;

vector<int> numOfDigit(ll n) {
    vector<int> v;
    while(n>0) {
        v.push_back(n%10);
        n/=10;
    }
    return v;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("AppendSort_1A_2021.in", "r", stdin);
    freopen("AppendSort_1A_2021.out", "w", stdout);
#endif

    int N, T;
    scanf("%d\n", &T);
    ll array[200];
    for (int o = 1; o <= T; o++)
    {
        scanf("%d\n", &N);
        memset(array, 0, 200*sizeof(ll));

        for(int u = 0; u<N; u++) {
            scanf("%lld", &array[u]);
        }
        int result = 0;
        for(int i=0;i<N-1;i++) {
            if(array[i] < array[i+1]) continue;

            if(array[i] == array[i+1]) {
                array[i+1] *= 10;
                result += 1;
            }

            if(array[i] > array[i+1]) {
                vector<int> v1 = numOfDigit(array[i]);
                vector<int> v2 = numOfDigit(array[i+1]);

                int offset = 1;
                int t = (v1.size() - v2.size());
                result += t;
                for(int x=0;x<t;x++) {
                    v2.push_back(0);
                    array[i+1] *= 10;
                    array[i+1] += 9;
                    offset *= 10;
                }

                if(array[i] >= array[i+1]) {
                    array[i+1] /= offset;
                    for(int x=0;x<t + 1;x++) {
                        array[i+1] *= 10;
                    }
                    result += 1;
                } else {
                    if (offset < array[i+1] - array[i]) {
                        array[i+1] /= offset;
                        for(int x=0;x<t;x++) {
                            array[i+1] *= 10;
                        }
                    } else {
                        array[i+1] = array[i] + 1;
                    }
                }
            }
        }

#ifdef FILEIO
        for(int x=0;x<N;x++) {
            cout << array[x] << " ";
        }
        cout << endl;
#endif  

        cout << "Case #" << o <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}