#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size());

        for(int i=0;i<nums.size()/2;i++) {
            result[2*i] = nums[i];
        }

        for(int i=0;i<nums.size()/2;i++) {
            result[2*i+1] = nums[i+nums.size()/2];
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3,4,4,3,2,1
    };

    int n = c.size()/2;
    vector<int> result = s.shuffle(c, n);
    for(auto x: result) {
        cout << x <<" ";
    }

    cout<< endl;
}