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
        if(t.size() > 0)
            result.push_back(t);
        return result;
    }
    char toLower(char c) {
        if (c >= 'A' && c<='Z') {
            c = c - ('Z' - 'z');
        }
        return c;
    }
    string toGoatLatin(string S) {
        vector<string> t = splitByChar(S, ' ');
        map<char, int> c = { {'a', 1}, {'o',1}, {'e',1}, {'i',1}, {'u', 1}};
        string result;
        for(int i=0;i<t.size();i++) {
            string x = t[i];
            if(x.size() >= 1) {
                if (c.count(toLower(x[0])) > 0) {
                    x+="ma";
                } else {
                    x.push_back(x[0]);
                    x+="ma";
                    x = x.substr(1);
                }

                for(int m=0;m<=i;m++) {
                    x.push_back('a');
                }
                result += (x + " ");
            }
        }
        return result.substr(0, result.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "I speak Goat Latin";

    string result = s.toGoatLatin(str);
    cout<<result<<endl;
}