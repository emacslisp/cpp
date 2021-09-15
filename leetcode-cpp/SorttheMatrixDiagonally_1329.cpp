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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int i=0;i<mat[0].size();i++) {
            int y = i;
            int x = 0;
            vector<int> value;
            vector<pair<int,int>> p;
            while(y < mat[0].size() && x < mat.size()) {
                value.push_back(mat[x][y]);
                p.push_back(pair<int, int>(x, y));
                x++;
                y++;
            }

            sort(value.begin(), value.end());

            for(int l=0;l<value.size();l++) {
                pair<int,int> xy = p[l];
                mat[xy.first][xy.second] = value[l];
            }
        }

        for(int j=1;j<mat.size();j++) {
            int x = j;
            int y = 0;
            vector<int> value;
            vector<pair<int,int>> p;
            while(x < mat.size() && y < mat[0].size()) {
                value.push_back(mat[x][y]);
                p.push_back(pair<int, int>(x, y));
                x++;
                y++;
            }

            sort(value.begin(), value.end());

            for(int l=0;l<value.size();l++) {
                pair<int,int> xy = p[l];
                mat[xy.first][xy.second] = value[l];
            }
        }

        return mat;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};

    string str = "codeleet";
    int n = 1804289383;
    vector<vector<int>> result = s.diagonalSort(c);

    for(auto x: result) {
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}