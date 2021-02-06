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
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words = splitByChar(text, ' ');
        map<string, vector<string>> m;
        vector<string> result;
        m[first + " " + second] = result;
        for(int i=0;i<=words.size() - 3;i++) {
            string index = words[i] + " " + words[i + 1];
            if(m.count(index) > 0) {
                m[first + " " + second].push_back(words[i+2]);
            }
        }

        return m[first + " " + second];
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string text = "we will we will rock you";
    string first = "we";
    string second = "will";

    vector<string>  result = s.findOcurrences(text, first, second);
    for(string x: result)
        cout<<x<<endl;
}