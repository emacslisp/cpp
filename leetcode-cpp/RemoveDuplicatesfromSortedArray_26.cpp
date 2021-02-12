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
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int p = nums[0];
        int i = 1;
        while(i< nums.size()) {
            if(nums[i] == p) {
                nums.erase(nums.begin() + i);
            } else {
                p = nums[i];
                i++;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1
    };

    string str = "codeleet";

    int result = s.removeDuplicates(c);
    cout<<result<<endl;

    for(int x: c) {
        cout<< x << endl;
    }
}