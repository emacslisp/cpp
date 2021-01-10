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
    int heightChecker(vector<int>& heights) {
        vector<int> copy;
        for(int x: heights) {
            copy.push_back(x);
        }
        sort(copy.begin(), copy.end());
        int result = 0;
        for (int i=0;i<heights.size();i++) {
            if(copy[i] != heights[i]) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       5,1,2,3,4
    };

    string str = "codeleet";

    int result = s.heightChecker(c);
    cout<<result<<endl;
}