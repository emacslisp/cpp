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
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;

        for(auto x : edges) {
            m[x[0]] ++;
            m[x[1]] ++;
        }

        for(auto x: m) {
            if(x.second == edges.size()) {
                return x.first;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,2},{2,3},{4,2}};

    string str = "codeleet";
    int n = 1804289383;
    int result = s.findCenter(c);
    cout<<result<<endl;
}