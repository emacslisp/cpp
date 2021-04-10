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

#define ll long long

long pickup(long sum, long prod, int offset, int left, vector<int> &v) {
    if(left == 0) return 0;
    if(prod > sum) return 0;
    if(offset >= v.size()) return 0;

    if(left == 1) {
        ll result = 0;
        for(int i=offset;i<v.size();i++) {
            if((sum - v[i]) == prod*v[i]) {
                if(result < (sum-v[i])) {
                    result = sum - v[i];
                }
            }
        }
        return result;
    } else {
        ll result = 0;
        for(int i=offset;i<v.size();i++) {
            int t = pickup(sum - v[i], prod*v[i], i+1, left - 1, v);
            if(result < t) {
                result = t;
            }
        }
        return result;
    }

}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("PrimeTime_B_1A_2021.in", "r", stdin);
    freopen("PrimeTime_B_1A_2021.out", "w", stdout);
#endif

    int N, T;
    scanf("%d\n", &T);
    int array[1000][2];
    for (int o = 1; o <= T; o++)
    {
        scanf("%d\n", &N);
        memset(array, 0, 1000*2*sizeof(int));

        for(int u = 0; u<N; u++) {
            scanf("%d %d\n", &array[u][0], &array[u][1]);
        }

        ll sum = 0;

        for(int i=0;i<N;i++) {
            sum += (array[i][0] * array[i][1]);
        }

        vector<int> v;
        for(int i=0;i<N;i++) {
            for(int j=0;j<array[i][1];j++) {
                v.push_back(array[i][0]);
            }
        }
        sort(v.begin(), v.end());
        ll result = 0;
        for(int i=1;i<=v.size()/2;i++) {
            ll t = pickup(sum, 1, 0, i, v);
            if(result < t) {
                result = t;
            }
        }
        
        cout << "Case #" << o <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}