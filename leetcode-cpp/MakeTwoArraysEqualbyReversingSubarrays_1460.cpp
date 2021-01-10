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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        if(target.size() != arr.size()) return false;

        for(int i=0;i<target.size();i++) {
            if(target[i] != arr[i])
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3,4
    };

    vector<int> d
    {
       2,4,1,3
    };

    string str = "codeleet";

    bool result = s.canBeEqual(c, d);
    cout<<result<<endl;
}