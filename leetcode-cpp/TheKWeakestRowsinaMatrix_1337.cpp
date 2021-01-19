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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> m(100, vector<int>());

        for(int i=0;i<mat.size();i++) {
            int counter = 0;
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j] == 1) {
                    counter++;
                }
            }

            m[counter].push_back(i);
        }

        vector<int> result;
        int left = k;
        int counter = 0;
        while(true) {
            vector<int> t = m[counter];
            counter++;
            if(t.size() == 0) {
                continue;
            }

            for(int x: t) {
                result.push_back(x);
                left--;
                if(left == 0) {
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,1,0,0,0},
 {1,1,1,1,0},
 {1,0,0,0,0},
 {1,1,0,0,0},
 {1,1,1,1,1}};

    string str = "codeleet";
    int k = 3;
    vector<int> result = s.kWeakestRows(c, k);
    for(int x: result)
        cout<<x<<endl;
}