#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int total = 0;
        for(auto itr : nums) {
            total+=itr;
            result.push_back(total);
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<int> input;
    for(int i=1;i<=10;i++) {
        input.push_back(i);
    }

    vector<int> result = s.runningSum(input);
    for(auto itr : result) {
        cout << itr <<endl;
    }
}