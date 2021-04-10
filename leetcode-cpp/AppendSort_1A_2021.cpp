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
    reverse(v.begin(), v.end());
    return v;
}

int compare(vector<int> v1, vector<int> v2) {
    if(v1.size() > v2.size()) return 1;
    if(v1.size() < v2.size()) return -1;

    for(int i=0;i<v1.size();i++) {
        if(v1[i] > v2[i]) {
            return 1;
        } else if(v1[i] < v2[i]) {
            return -1;
        }
    }
    return 0;
}

vector<int> minute(vector<int> v1, vector<int> v2) {
    vector<int> result;
    for(int i=0;i<v1.size();i++) {
        result.push_back(v1[i]- v2[i]);
    }

    for(int i=0;i<result.size();) {
        if(result[i] == 0) {
            result.erase(result.begin() + i);
        } else {
            break;
        }
    }

    for(int i=0;i<result.size();i++) {
        if(result[i] < 0) {
            result[i]+=10;
            result[i-1] -= 1;
        }
    }
    return result;
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
        ll result = 0;
        vector<vector<int> > v;
        for(int i=0;i<N;i++) {
            v.push_back(numOfDigit(array[i]));
        }

        for(int i=0;i<N-1;i++) {
            if(compare(v[i], v[i+1]) == -1) continue;

            if(compare(v[i],v[i+1]) == 0) {
                v[i+1].push_back(0);
                result += 1;
            }

            if(compare(v[i],v[i+1]) == 1) {
                vector<int> v3;
                vector<int> offset;
                for(int x: v[i + 1]) {
                    v3.push_back(x);
                }

                ll t = (v[i].size() - v[i+1].size());
                offset.push_back(1);
                result += t;
                for(int x=0;x<t;x++) {
                    v3.push_back(9);
                    offset.push_back(0);
                }

                if(compare(v[i],v3) >= 0) {
                    for(int x=0;x<t + 1;x++) {
                        v[i+1].push_back(0);
                    }
                    result += 1;
                } else {
                    if (compare(offset, minute(v3, v[i])) == -1) {
                        for(int x=0;x<t;x++) {
                            v[i+1].push_back(0);
                        }
                    } else {
                        v[i+1].clear();
                        for(int x=0;x<v[i].size();x++) {
                            v[i+1].push_back(v[i][x]);
                        }

                        v[i+1][v[i+1].size() - 1] += 1;
                    }
                }
            }
        }

#ifdef FILEIO
        for(int x=0;x<N;x++) {
            for(int y: v[x]) {
            cout << y;
            }
        cout << " ";

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