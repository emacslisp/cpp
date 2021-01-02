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
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int sum = 0;
        
        for(int i=0;i<m;i++) {
            sum += nums[i];
        }

        if(sum % 2 == 1) return false;
        sum /= 2;

        vector<vector<int>> dp(sum + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= sum; i++) {
            for(int j=0;j<nums.size();j++) {
                if(nums[j] > sum) return false;
                if (nums[j] <= i) 
                    dp[i][j+1] = Max(dp[i][j], nums[j] + dp[i-nums[j]][j]);
            }
        }

        return dp[sum][m] == sum;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3,5
    };

    bool result = s.canPartition(c);
    cout<<result<<endl;
}