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
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> c(n, vector<int>(m, 0));

        for (int i=0;i<indices.size();i++) {
            vector<int> t = indices[i];
            for (int k=0;k<m;k++) {
                c[t[0]][k]++;
            }

            for (int k=0;k<n;k++) {
                c[k][t[1]]++;
            }
        }
        int result = 0;
        for(int i=0;i<c.size();i++) {
            for(int j=0;j<c[0].size();j++) {
                // cout << c[i][j] << " ";
                if(c[i][j]%2 ==1) {
                    result++;
                }
            }
            // cout << endl;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {
       {0, 1},
       {1, 1}
    };

    int n = 2;
    int m = 3;

    int result = s.oddCells(n,m,c);
    cout<<result<<endl;
}