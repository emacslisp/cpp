#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=1;i<n;i++) {
            grid[0][i] += grid[0][i-1];
        }

        for(int i=1;i<m;i++) {
            grid[i][0] += grid[i-1][0];
        }

        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,2,3},{4,5,6}};

    string str = "codeleet";
    int n = 1804289383;
    int result = s.minPathSum(c);
    cout<<result<<endl;
}