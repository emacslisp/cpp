#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int dp[1001][1001];
    map<string,int> m;
    int foo(vector<int>& nums, vector<int>& multipliers, int index,int start, int end) {
        if (dp[start][index] != INT_MIN) return dp[start][index];

        if (index == multipliers.size() - 1) {
            return max(nums[start] *multipliers[index], nums[end] *multipliers[index]);
        }
        
        int x = foo(nums, multipliers, index+1, start + 1, end) + nums[start] *multipliers[index];
        int y = foo(nums, multipliers, index+1, start, end - 1) + nums[end] *multipliers[index];

        dp[start][index] = max(x,y);
        return dp[start][index];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int start = 0;
        int end = nums.size() - 1;
        int sum = 0;
        for(int i=0;i<1001;i++) {
            for(int j=0;j<1001;j++) {
                dp[i][j] = INT_MIN;
            }
        }
        return foo(nums,multipliers,0, start, end);
    }
};

int main() {
    Solution s;
    vector<int> nums
    {-5,-3,-3,-2,7,1};

    vector<int> multipliers
    {-10,-5,3,4,6};

    string str = "codeleet";

    int result = s.maximumScore(nums, multipliers);
    cout<<result<<endl;
}