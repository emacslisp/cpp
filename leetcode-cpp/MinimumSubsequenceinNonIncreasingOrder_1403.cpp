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
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());
        sum = sum/2;
        vector<int> result;

        for (int i=nums.size() - 1;i>=0;i--) {
            if(sum > nums[i]) {
                result.push_back(nums[i]);
                sum -= nums[i];
            } else if(sum == nums[i]) {
                result.push_back(nums[i]);
                result.push_back(nums[i-1]);
                break;
            } else {
                result.push_back(nums[i]);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       6
    };

    string str = "codeleet";

    vector<int> result = s.minSubsequence(c);
    for(int x: result) {
        cout<<x<<endl;
    }
}