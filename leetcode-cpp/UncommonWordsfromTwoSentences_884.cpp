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
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> va = splitByChar(A, ' ');
        vector<string> vb = splitByChar(B, ' ');

        map<string, int> m;
        for(string x: va) {
            if(m.count(x) == 0) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }

        for(string x: vb) {
            if(m.count(x) == 0) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }
        vector<string> result;
        for(auto x: m) {
            if(x.second == 1) {
                result.push_back(x.first);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string A = "apple apple";
    string B = "banana";

    vector<string> result = s.uncommonFromSentences(A, B);

    for(string x: result)
        cout<<x<<endl;
}