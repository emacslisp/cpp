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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size(), vector<int>(A.size(), 0));

        for(int i=0;i<A.size();i++) {
            for(int j=0;j<A[0].size();j++) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    
}