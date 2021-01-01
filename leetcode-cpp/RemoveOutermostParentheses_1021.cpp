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
    string removeOuterParentheses(string S) {
        int level = 0;
        int index = 0;
        vector<string> str;
        for(int i=0;i<S.size();i++) {
            if (S[i]== '(') {
                level++;
            } else if(S[i] == ')') {
                level--;
            }

            if (level == 0) {
                // cout<< S.substr(index, i - index+1) << endl;
                str.push_back(S.substr(index, i - index + 1));
                index = i + 1;
            }
        }
        string output;
        for(string s: str) {
            output += s.substr(1, s.size() - 2);
        }
        return output;
    }
};

int main() {
    Solution s;

    // string str = "(()())(())";
    string str = "(()())(())(()(()))";

    string result = s.removeOuterParentheses(str);
    cout<<result<<endl;
}