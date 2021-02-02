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
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        int s = 0;
        sum.push_back(0);
        for(int i=0;i<nums.size();i++) {
            s += nums[i];
            sum.push_back(s);
        }

        int m = max(sum[1], sum[sum.size() - 1]);
        for(int i=0;i<sum.size();i++) {
            for(int j=i+1;j<sum.size();j++) {
                if( m < (sum[j] - sum[i])) {
                    m = sum[j] - sum[i];
                }
            }
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -1, -2
    };

    string str = "codeleet";

    int result = s.maxSubArray(c);
    cout<<result<<endl;
}