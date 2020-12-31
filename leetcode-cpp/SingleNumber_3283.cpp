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
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i=1;i<nums.size();i++) {
            result ^= nums[i];
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,2,1
    };

    int result = s.singleNumber(c);
    cout<<result<<endl;
}