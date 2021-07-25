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
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1;
        return nums[end] * nums[end-1] - nums[0] * nums[1];
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,2,5,9,7,4,8
    };

    string str = "codeleet";
    int n = 1804289383;
    int result = s.maxProductDifference(c);
    cout<<result<<endl;
}