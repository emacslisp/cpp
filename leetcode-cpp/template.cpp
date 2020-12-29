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
    string restoreString(string s, vector<int>& indices) {
        vector<char> result(s.size());

        for(int i=0;i<s.size();i++) {
            result[indices[i]] = s[i];
        }
        string str(result.begin(), result.end());
        return str;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";

    string result = s.restoreString(str, c);
    cout<<result<<endl;
}