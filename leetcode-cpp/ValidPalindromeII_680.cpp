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
    bool foo(string s) {
        int m = s.size()/2;
         bool isValidPalindrome = true;
        for (int i=0;i<m;i++) {
            if(s[i] == s[s.size() - i - 1]) {
                continue;
            }
            else {
                isValidPalindrome = false;
                break;
            }
        }
        return isValidPalindrome;
    }
    bool validPalindrome(string s) {
        int m = s.size()/2;
        bool isValidPalindrome = true;
        for (int i=0;i<m;i++) {
            if(s[i] == s[s.size() - i - 1]) {
                continue;
            } else {
                isValidPalindrome = false;
                string substr = s.substr(i, s.size() - 2*i - 1);
                string substr2 = s.substr(i+1, s.size() - 2*i - 1);
                if (foo(substr) || foo(substr2)) {
                    isValidPalindrome = true;
                }
                break;
            }
        }

        return isValidPalindrome;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "abc";

    bool result = s.validPalindrome(str);
    cout<<result<<endl;
}