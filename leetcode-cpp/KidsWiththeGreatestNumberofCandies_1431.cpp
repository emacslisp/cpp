#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max = 0;
        for(int x : candies) {
            if(max < x) {
                max = x;
            }
        }

        for(int x: candies) {
            if(x+extraCandies < max) {
                result.push_back(false);
            }
            else {
                result.push_back(true);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,3,5,1,3
    };

    int extra = 3;
    vector<bool> result = s.kidsWithCandies(c, extra);
    for(bool x: result) {
        cout << x <<" ";
    }

    cout<< endl;
}