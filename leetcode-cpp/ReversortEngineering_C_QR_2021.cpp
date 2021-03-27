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

void revert(vector<int> &v, int start, int end) {
    while(start < end) {
        int t = v[start];
        v[start] = v[end];
        v[end] = t;
        start++;
        end--;
    }
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("ReversortEngineering_C_QR_2021.in", "r", stdin);
    freopen("ReversortEngineering_C_QR_2021.out", "w", stdout);
#endif

    int T;
    scanf("%d\n", &T);
    for (int o = 1; o <= T; o++)
    {
        int N,C;
        scanf("%d %d\n", &N, &C);

        int max = N*(N+1)/2 - 1;
        int min = N-1;

        if(C<min || C>max) {
            cout << "Case #" << o <<": "<< "IMPOSSIBLE" << endl;
            continue;
        }

        // vector<int> v;
        // for(int i=1;i<=N;i++) v.push_back(i);

        vector<int> offset(N-1, 1);

        int p = C - (N-1);
        int len = N-1;

        int index = 0;

        while(p > 0 && p>=len) {
            offset[index++] += len;
            p-=len;
            len--;
        }

        if(p>0 && index < N)
            offset[index++] += p;

        vector<int> v;
        v.push_back(N);
        for(int i=offset.size() - 1;i>=0;i--) {
            v.insert(v.begin(), (i+1));
            revert(v, 0, offset[i] - 1);
        }

        string result = "";

        for(int i=0;i<v.size()-1;i++) {
            result += to_string(v[i]);
            result += " ";
        }

        result += to_string(v[v.size() - 1]);

        cout << "Case #" << o <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}