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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))

class TPair {
public:
    int start;
    int end;
    int index;
    TPair() {
         this->start = 0;
        this->end = 0;
        this->index = 0;
    }
    TPair(int start, int end, int index) {
        this->start = start;
        this->end = end;
        this->index = index;
    }
};

bool cmp(TPair& a, 
            TPair& b) 
    { 
        return a.start < b.start; 
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
        vector<TPair> vp;
        for(int u = 0; u<N; u++) {
            TPair p(array[u][0], array[u][1], u);
            vp.push_back(p);
        }

        vector<TPair> cj(2);
        cj[0] = TPair(0,0,0);
        cj[1] = TPair(0,0,0);
        string result(N, '.');

        sort(vp.begin(), vp.end(), cmp);
        for(int i=0;i<vp.size();i++) {
                TPair tp = vp[i];
                if(cj[0].end<=tp.start) {
                    result[tp.index] = 'C';
                    cj[0] = tp;
                }
                else if(cj[1].end<=tp.start) {
                    result[tp.index] = 'J';
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