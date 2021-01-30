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
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int min = INT_MAX;
        for(int x: nums) {
            sum += x;
            if(min > sum) {
                min = sum;
            }
        }

        if(min <= 0 )
            return -min+1;

        return 1;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2, -2, 1
    };

    string str = "codeleet";

    int result = s.minStartValue(c);
    cout<<result<<endl;
}