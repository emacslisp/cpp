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
    int minInsertions(string s) {
        string str;
        for(int i=s.size() - 1;i>=0;i--) {
            str.push_back(s[i]);
        }

        cout<<str<<endl;

        return s.size() - LCS(s, str);
    }

    int LCS(string s1, string s2) {
        vector<vector<int>> c(s1.size()+1, vector<int>(s2.size()+1, 0));

        for(int i=1;i<=s1.size();i++) {
            for(int j=1;j<=s2.size();j++) {
                if(s1[i-1] == s2[j-1]) {
                    c[i][j] = 1 + c[i-1][j-1];
                } else {
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
                }
            }
        }

        return c[s1.size()][s2.size()];
    }
};

int main() {
    Solution s;

    string str = "Ab3bd";

    int result = s.minInsertions(str);
    cout<<result<<endl;
}