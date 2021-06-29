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
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for(auto o: queries) {
            int index = 0;
            int x = o[0];
            int y = o[1];
            int r = o[2];

            for(auto p: points) {
                int x1 = p[0];
                int y1 = p[1];

                if( r*r >= ((x-x1)*(x-x1) + (y-y1)*(y-y1))) {
                    index++;
                }
            }
            result.push_back(index);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points
    {{1,3},{3,3},{5,3},{2,2}};

    vector<vector<int>> queries
    {{2,3,1},{4,3,1},{1,1,2}};

    string str = "codeleet";
    int n = 1804289383;
    vector<int> result = s.countPoints(points, queries);
    for(auto x: result)
    cout<<x<<endl;
}