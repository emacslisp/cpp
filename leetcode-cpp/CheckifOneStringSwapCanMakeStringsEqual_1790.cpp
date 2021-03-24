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
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;

        vector<int> diff;
        int count = 0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] != s2[i]) {
                count ++;
                diff.push_back(i);
            }
        }

        if(count == 0) return true;

        if(count == 2) {
            int i1 = diff[0];
            int i2 = diff[1];

            if(s1[i1] == s2[i2] && s1[i2] == s2[i1]) {
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
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    string str1, str2;
    str1 = "bank";
    str2 = "kanb";
    bool result = s.areAlmostEqual(str1, str2);
    cout<<result<<endl;
}