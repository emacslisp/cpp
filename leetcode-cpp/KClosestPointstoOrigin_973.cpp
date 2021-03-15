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

class tobj {
public: 
    vector<int> t;
    int d;
    tobj(int d, vector<int> t) {
        this->d = d;
        this->t = t;
    }
};

bool cmp(tobj t1, tobj t2) {
    return t1.d < t2.d;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<tobj> v;
        
        for(auto x: points) {
            int d = x[0]*x[0] + x[1]*x[1];
            tobj to(d, x);
            v.push_back(to);
        }

        sort(v.begin(), v.end(), cmp);
        vector<vector<int>> result;
        for(int i=1;i<=k;i++) {
            result.push_back(v[i-1].t);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points 
    {{3,3},{5,-1},{-2,4}};

    string str = "codeleet";
    int n = 2;
    vector<vector<int>>  result = s.kClosest(points, n);
    for(auto x: result) {
        cout<<x[0] << " " << x[1] <<endl;
    }
}