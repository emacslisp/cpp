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
    bool check(vector<int>& nums) {
        vector<int> v(2*nums.size(), 0);
        for(int i=0;i<nums.size();i++) {
            v[i] = nums[i];
            v[nums.size() + i] = nums[i];
        }

        for(int i=0;i<nums.size();i++) {
            bool isValid = true;
            for(int j=i;j<i+nums.size() - 1;j++) {
                if(v[j] > v[j+1]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,1,3,4
    };

    string str = "codeleet";

    bool result = s.check(c);
    cout<<result<<endl;
}