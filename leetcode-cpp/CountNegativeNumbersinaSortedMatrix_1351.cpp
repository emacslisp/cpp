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
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] < 0) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {
      {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}
    };


    int result = s.countNegatives(c);
    cout<<result<<endl;
}