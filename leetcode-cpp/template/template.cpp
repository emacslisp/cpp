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
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    int arrangeCoins(int n) {
        ll c = (ll)8*(ll)n + (ll)1;
        int level = (sqrt(c) - 1)/2;
        
        return level;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int n = 1804289383;
    int result = s.arrangeCoins(n);
    cout<<result<<endl;
}