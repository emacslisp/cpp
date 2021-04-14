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
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)

class Solution {
public:
    int surfaceArea(vector<vector<int> >& grid) {
        int total = 0;
        for(vector<int> x: grid) {
            for(int t : x) {
                total += 6*t;
                if(t > 1)
                    total -= 2*(t - 1);
            }

            fora(i, 0 , x.size() - 1) {
                total -= 2*min(x[i], x[i+1]);
            }
        }
        fora(i,0,grid[0].size()) {
            fora(j,0,grid.size() - 1) {
                total -= 2*min(grid[j][i], grid[j+1][i]);
            }
        }

        return total;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,1,1},{1,0,1},{1,1,1}};

    string str = "codeleet";
    int n = 1804289383;
    int result = s.surfaceArea(c);
    cout<<result<<endl;
}