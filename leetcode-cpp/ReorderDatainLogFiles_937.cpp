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
    bool isDigit(string s) {
        for(char c:s) {
            if(!(c - '0' >=0 && c-'0'<=9)) {
                return false;
            }
        }
        return true;
    }
    int compare(string a, string b) {
        for(int i=0;i<min(a.size(), b.size());i++) {
            if(a[i] > b[i]) {
                return 1;
            } else if(a[i] < b[i]) {
                return -1;
            }
        }

        if(a.size() == b.size()) {
            return 0;
        }

        return a.size() > b.size()? 1 : -1;
    }

bool cmp(string & a, 
           string & b) 
    { 
        vector<string> t1 = splitByChar(a, ' ');
        vector<string> t2 = splitByChar(b, ' ');

        string id1 = t1[0];
        string id2 = t2[0];

        for(int i=1;i<min(t1.size(), t2.size());i++) {
            if (compare(t1[i], t2[i]) == 1) {
                return false;
            } else if(compare(t1[i], t2[i]) == -1) {
                return true;
            }
        }

        if(t1.size() == t2.size()) {
            return compare(id1, id2) == 1 ? false: true;
        }

        return t1.size() > t2.size()? false: true;
    } 
class Solution {
public:   
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> str;
        vector<string> digit;
        for(string x: logs) {
            vector<string> t = splitByChar(x, ' ');
            if(t.size() >= 2 && isDigit(t[1])) {
                digit.push_back(x);
            } else {
                str.push_back(x);
            }
        }

        vector<string> result;
        sort(str.begin(), str.end(), cmp);

        for(string x: str) {
            result.push_back(x);
        }

        for(string x: digit) {
            result.push_back(x);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"
    };

    string str = "codeleet";

    vector<string> result = s.reorderLogFiles(c);
    for(string x: result)
     cout<<x<<endl;
}