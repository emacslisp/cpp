#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i+=2) {
            for(int j=0;j<nums[i];j++) {
                result.push_back(nums[i+1]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums { 1,1,2,3 };
    vector<int> result = s.decompressRLElist(nums);

    for(auto x: result) {
        cout << x <<" ";
    }

    cout<< endl;
}