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

class TObj {
public:
    vector<int> o;
    int hDistance;
    TObj() {
        
    }
};

bool cmp(TObj& a, 
            TObj& b) 
    { 
        return a.hDistance < b.hDistance; 
    } 

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<TObj> r;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                int hDistance = abs(i - r0) + abs(j - c0);
                TObj tObj;
                tObj.hDistance = hDistance;
                tObj.o.push_back(i);
                tObj.o.push_back(j);
                r.push_back(tObj);
            }
        }

        sort(r.begin(), r.end(), cmp);
        vector<vector<int>> output;
        for(TObj x: r) {
            output.push_back(x.o);
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int R,C,r0,c0;
    R = 2;
    C = 3;
    r0 = 1;
    c0 = 2;

    vector<vector<int>> result = s.allCellsDistOrder(R, C, r0, c0);
    for(auto x: result) {
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}