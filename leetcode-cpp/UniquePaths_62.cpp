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
    int grid[102][102];
    int findPath(int m, int n) {
        if(m == 0 || n == 0) return 1;
        if(grid[m][n] > 0) return grid[m][n];
        int x = findPath(m-1, n);
        int y = findPath(m, n-1);

        grid[m][n] = x + y;
        return grid[m][n];
    }
    int uniquePaths(int m, int n) {
        for(int i=0;i<102;i++) {
            for(int j=0;j<102;j++) {
                grid[i][j] = -1;
            }
        }

        return findPath(m-1,n-1);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int m = 4;
    int n = 8;
    int result = s.uniquePaths(m, n);
    cout<<result<<endl;
}