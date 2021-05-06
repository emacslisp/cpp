#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m;
        int y = n;
        for(auto t: ops) {
            x = min(t[0], x);
            y = min(t[1], y);
        }

        return x*y;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}}};

    string str = "codeleet";
    int m = 40000;
    int n = 40000;

    int result = s.maxCount(m, n, c);
    cout<<result<<endl;
}