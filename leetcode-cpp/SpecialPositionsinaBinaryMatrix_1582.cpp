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
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> r;
        vector<int> c;
        for(int i=0;i<mat.size();i++) {
            int sum = 0;
            for(int j=0;j<mat[0].size();j++) {
                sum += mat[i][j];
            }
            r.push_back(sum);
        }

        for(int i=0;i<mat[0].size();i++) {
            int sum = 0;
            for(int j=0;j<mat.size();j++) {
                sum += mat[j][i];
            }
            c.push_back(sum);
        }
        int counter = 0;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j] == 1 && r[i] == 1 && c[j] == 1) {
                    counter++;
                }
            }
        }

        return counter;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{0,0,0,0,0},
{1,0,0,0,0},
{0,1,0,0,0},
{0,0,1,0,0},
{0,0,0,1,1}};

    string str = "codeleet";

    int result = s.numSpecial(c);
    cout<<result<<endl;
}