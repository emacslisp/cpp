#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
vector<string> splitByString(string s, string delim) {
    vector<string> result;
    auto start = 0U;
    auto end = s.find(delim);

    while (end != std::string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }

    result.push_back(s.substr(start, end - start));

    return result;
}

    string simplifyPath(string path) {
        vector<string> v = splitByString(path, "/");

        stack<string> st;
        stack<string> st2;

        for(string x: v) {
            if(x == "..") {
                if(st.size() > 0) st.pop();
            } else if(x=="." || x== "") {
                    // do nothing
            } else {
                st.push(x);
            }
        }

        while(st.size() > 0) {
            st2.push(st.top());
            st.pop();
        }
        string result = "";

        if(st2.size() == 0) result = "/";

        while(st2.size() > 0) {
            result += "/" + st2.top();
            st2.pop();
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

    string str = "/a/./b/../../c/";
    int n = 1804289383;
    string result = s.simplifyPath(str);
    cout<<result<<endl;
}