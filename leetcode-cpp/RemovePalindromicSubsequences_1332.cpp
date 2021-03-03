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
    int removePalindromeSub(string s) {
        string s1;
        for(char c: s) {
            s1.push_back(c);
        }
        reverse(s.begin(), s.end());

        if( s== s1) return 1;

        return 2;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "abba";

    int result = s.removePalindromeSub(str);
    cout<<result<<endl;
}