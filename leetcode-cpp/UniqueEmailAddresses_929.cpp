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
    vector<string> splitByChar(string s, char c) {
        vector<string> result;
        string t;
        for(int i=0;i<s.size();i++) {
            if(s[i] != c)
                t.push_back(s[i]);
            else {
                result.push_back(t);
                t = "";
            }
        }
        result.push_back(t);
        return result;
    }
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> m;
        for(string s: emails) {
            string t;
            vector<string> parts = splitByChar(s, '@');
            vector<string> p1 = splitByChar(parts[0], '+');

            for(char c:p1[0]) {
                if(c=='.') continue;

                t.push_back(c);
            }
            string f = t+"@"+parts[1];
            if (m.count(f) == 0) {
                m[f] = 1;
            }
        }

        return m.size();
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "test.email+alex@leetcode.com","test.email.leet+alex@code.com"
    };

    string str = "codeleet";

    int result = s.numUniqueEmails(c);
    cout<<result<<endl;
}