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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> sum;
        int result = 0;
        for(int i=0;i<nums.size();i++) {
            result += nums[i];
            sum.push_back(result);
        }

        vector<int> output;
        for(int i=0;i<nums.size();i++) {
            int r = ((i+1)*nums[i] - sum[i]) + ((sum[sum.size() - 1] - sum[i]) - (nums.size() - i - 1)*nums[i]);
            output.push_back(r);
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,4,6,8,10
    };

    vector<int> result = s.getSumAbsoluteDifferences(c);
    for(int x: result)
        cout<<x<<endl;
}