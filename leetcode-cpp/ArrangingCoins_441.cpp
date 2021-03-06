#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        #define ll long long
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