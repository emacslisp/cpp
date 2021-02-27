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
    string makeGood(string s) {
        stack<char> st;
        for(char c: s) {
            if(st.size() > 0) {
                char t = st.top();
                if(abs(c - t) == ('a' - 'A')) {
                    st.pop();
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }

        string result;
        while(st.size() > 0) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "abBAcC";

    string result = s.makeGood(str);
    cout<<result<<endl;
}