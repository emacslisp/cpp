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
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++) {
            result.push_back(nums[nums[i]]);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       0,2,1,5,3,4
    };

    string str = "codeleet";
    int n = 1804289383;
    vector<int> result = s.buildArray(c);
    for(int x: result)
    cout<<x<<endl;
}