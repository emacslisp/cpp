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
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[i].size();j++) {
                if(i == j || (i+j== mat.size() - 1 && i != j )) {
                    result += mat[i][j];
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
       {5}
    };

    int result = s.diagonalSum(c);
    cout<<result<<endl;
}