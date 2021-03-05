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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i=0;i<nums.size();i++) {
            if(m.count(nums[i]) == 0) {
                m[nums[i]] = i;
            } else {
                if((i - m[nums[i]]) <=k) {
                    return true;
                } else {
                    m[nums[i]] = i;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1, 0, 1, 1
    };

    string str = "codeleet";

    int k = 1;
    bool result = s.containsNearbyDuplicate(c, k);
    cout<<result<<endl;
}