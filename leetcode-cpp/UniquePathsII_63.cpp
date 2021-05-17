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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int grid[102][102];
        for(int i=0;i<102;i++) {
            for(int j=0;j<102;j++) {
                grid[i][j] = 0;
            }
        }

        grid[0][1] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(obstacleGrid[i-1][j-1] == 0) {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }

        return grid[m][n];
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid
    {{0,0,0},{0,1,0},{0,0,0}};

    string str = "codeleet";
    int m = 4;
    int n = 8;
    int result = s.uniquePathsWithObstacles(obstacleGrid);
    cout<<result<<endl;
}