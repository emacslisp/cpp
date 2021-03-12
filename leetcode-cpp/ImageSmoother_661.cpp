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
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int x = M.size() + 2;
        int y = M[0].size() + 2;
        vector<vector<int>> t(x, vector<int> (y, -1));

        vector<vector<int>> result;
        
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[0].size();j++) {
                t[i+1][j+1] = M[i][j];
            }
        }

        for(int i=1;i<=M.size();i++) {
            vector<int> f;
            for(int j=1;j<=M[0].size();j++) {

                int total = 0;
                int sum = 0;
                for(int k=i-1;k<=i+1;k++) {
                    for(int m=j-1;m<=j+1;m++) {
                        if(t[k][m] != -1) {
                            total++;
                            sum+=t[k][m];
                        }
                    }
                }
                f.push_back(sum/total);
            }
            result.push_back(f);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};

    string str = "codeleet";
    int n = 1804289383;
    vector<vector<int>> result = s.imageSmoother(c);

    for(vector<int> v : result) {
        for(int x : v) {
            cout<<x<<"\t";
        }
        cout << endl;
    }
    
}