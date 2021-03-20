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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        nums.push_back(-1);
        int start, end;
        start = nums[0];
        end = nums[0];

        for(int i=1;i<nums.size();i++) {
            if(nums[i] - nums[i-1] == 1) {
                end = nums[i];
            } else {
                if(start != end)
                    result.push_back(to_string(start)+"->"+to_string(end));
                else {
                    result.push_back(to_string(start));
                }
                start = nums[i];
                end = nums[i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       0,2,3,4,6,8,9
    };

    string str = "codeleet";
    vector<string> result = s.summaryRanges(c);
    for(string x: result)
        cout<<x<<endl;
}