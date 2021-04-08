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
    int findLUSlength(string a, string b) {
        if(a==b) return -1;

        return max(a.size(), b.size());
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "aaa";
    string str2 = "aab";
    int result = s.findLUSlength(str, str2);
    cout<<result<<endl;
}