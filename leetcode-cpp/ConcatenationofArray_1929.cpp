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
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> r;
        for(int x: nums) {
            r.push_back(x);
        }
        for(int x: nums) {
            r.push_back(x);
        }
        return r;
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
    vector<int> result = s.getConcatenation(c);
    for(auto x: result)
        cout<<x<<endl;
}