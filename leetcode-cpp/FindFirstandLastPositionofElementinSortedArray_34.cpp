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
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == target && start == -1) {
                start = i;
            }

            if(nums[i] == target) {
                end = i;
            }
        }

        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       5,7,7,8,8,10
    };

    string str = "codeleet";
    int target = 8;
    vector<int> result = s.searchRange(c, target);
    for(int x: result)
        cout<<x<<endl;
}