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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, vector<int>> m;
        vector<int> v;
        vector<int> result;

        for(int x:arr2) {
            m[x] = vector<int>(0);
        } 

        for(int x: arr1) {
            if(m.count(x) > 0) {
                m[x].push_back(x);
            } else {
                v.push_back(x);
            }
        }

        for(int x:arr2) {
            for(int y: m[x]) {
                result.push_back(y);
            }
        }
        sort(v.begin(), v.end());
        for(int x: v) {
            result.push_back(x);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,3,1,3,2,4,6,7,9,2,19
    };

    vector<int> c2
    {
       2,1,4,3,9,6
    };

    string str = "codeleet";

    vector<int> result = s.relativeSortArray(c, c2);
    for(int x: result)
    cout<<x<<endl;
}