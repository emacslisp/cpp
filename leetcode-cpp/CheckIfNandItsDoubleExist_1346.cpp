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
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(int x: arr) {
            m[x]++;
        }

        for(int x: arr) {
            if(x == 0) {
                if(m[x] >= 2) return true;
                continue;
            }
            if(m.count(2*x)>0) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -2,0,10,-19,4,6,-8
    };

    string str = "codeleet";

    bool result = s.checkIfExist(c);
    cout<<result<<endl;
}