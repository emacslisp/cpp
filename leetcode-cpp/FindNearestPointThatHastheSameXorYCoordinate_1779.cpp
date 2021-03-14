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
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        map<int, vector<int>> m;
        int min = 1000001;
        int count = 0;
        for(vector<int> t: points) {
            if(x == t[0] || y == t[1]) {
                int d = abs(x - t[0]) + abs(y - t[1]);
                if(m.count(d) == 0) {
                    vector<int> v;
                    v.push_back(count);
                    m[d] = v;
                }
            }
            count++;
        }

        for(auto t : m) {
            if(min > t.first) {
                min = t.first;
            }
        }

        if(m.size() == 0) return -1;

        return m[min][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,2},{3,1},{2,4},{2,3},{4,4}};

    string str = "codeleet";
    int x,y;
    x = 3;
    y = 4;

    int result = s.nearestValidPoint(x, y, c);
    cout<<result<<endl;
}