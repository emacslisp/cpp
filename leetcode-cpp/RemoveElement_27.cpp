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
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        while(i<nums.size()) {
            if(nums[i] == val) {
                nums.erase(nums.begin() + i);
            } else {
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
       0,1,2,2,3,0,4,2
    };

    string str = "codeleet";
    int val = 2;
    int result = s.removeElement(c, val);
    cout<<result<<endl;

    for(int x: c) {
        cout << x << endl;
    }
}