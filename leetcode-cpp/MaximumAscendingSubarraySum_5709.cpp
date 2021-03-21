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

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int start = nums[0];
        int sum = start;
        int maxSum = 0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > start) {
                sum += nums[i];
                start = nums[i];
            } else {
                if(maxSum < sum) {
                    maxSum = sum;
                }
                start = nums[i];
                sum = start;
            }
        }

        if(maxSum < sum) {
            maxSum = sum;
        }

        return maxSum;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       3,6,10,1,8,9,9,8,9
    };

    string str = "codeleet";
    int n = 1804289383;
    int result = s.maxAscendingSum(c);
    cout<<result<<endl;
}