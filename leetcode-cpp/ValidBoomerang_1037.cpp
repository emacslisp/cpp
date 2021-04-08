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
    bool isBoomerang(vector<vector<int> >& points) {
        int a1 = points[0][0];
        int b1 = points[0][1];
        int a2 = points[1][0];
        int b2 = points[1][1];
        int a3 = points[2][0];
        int b3 = points[2][1];

        int t = (b1 - b2)*(a3 - a1) - (a1 - a2) *(b3 - b1);

        return t!=0;
    }
};

int main() {
    Solution s;
    vector<vector<int> > c
    {
       {1,0},{2,0},{3,0}
    };

    string str = "codeleet";
    int n = 1804289383;
    bool result = s.isBoomerang(c);
    cout<<result<<endl;
}