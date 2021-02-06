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
bool cmp(pair<int, int>& a, 
            pair<int, int>& b) 
    { 
        return a.first < b.first; 
    } 

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("ParentingPartneringReturns_2020_C.in", "r", stdin);
    freopen("ParentingPartneringReturns_2020_C.out", "w", stdout);
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
        vector<pair<int,int>> vp;
        map<pair<int,int>,int> m;
        for(int u = 0; u<N; u++) {
            pair<int, int> p = pair<int, int> (array[u][0], array[u][1]);
            vp.push_back(p);
            m[p] = u;
        }

        vector<pair<int,int>> cj(2);
        cj[0] = pair<int,int>(0, 0);
        cj[1] = pair<int,int>(0, 0);
        string result(N, '.');

        sort(vp.begin(), vp.end(), cmp);
        for(int i=0;i<vp.size();i++) {
                pair<int, int> tp = vp[i];
                if(cj[0].second<=tp.first) {
                    result[m[tp]] = 'C';
                    cj[0] = tp;
                }
                else if(cj[1].second<=tp.first) {
                    result[m[tp]] = 'J';
                    cj[1] = tp;
                } else {
                    result = "IMPOSSIBLE";
                    break;
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