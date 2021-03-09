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
    string gcdOfStrings(string str1, string str2) {

        if(str1 == str2) return str1;

        if(str1.size() < str2.size())
            return gcdOfStrings(str2, str1);
        
        size_t p = str1.find(str2);
        if(p != 0) return "";

        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "LEET";
    string s2 = "CODE";
    int n = 1804289383;
    string result = s.gcdOfStrings(str, s2);
    cout<<result<<endl;
}