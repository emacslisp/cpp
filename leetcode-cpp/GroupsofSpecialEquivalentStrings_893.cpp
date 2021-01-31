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
    int numSpecialEquivGroups(vector<string>& A) {
        vector<char> a,b;
        map<string, int> m;
        string y;
        for(string x: A) {
            a.clear();
            b.clear();
            for(int i=0;i<x.size();i+=2) {
                a.push_back(x[i]);
                b.push_back(x[i+1]);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            y="";
            for(char m: a) y.push_back(m);
            for(char m: b) y.push_back(m);
            if(m.count(y) == 0) {
                m[y] = 1;
            } else {
                m[y]++;
            }
        }

        return m.size();
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "abc","acb","bac","bca","cab","cba"
    };

    string str = "codeleet";

    int result = s.numSpecialEquivGroups(c);
    cout<<result<<endl;
}