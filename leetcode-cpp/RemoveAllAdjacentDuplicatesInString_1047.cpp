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
    string removeDuplicates(string S) {
        stack<char> ss;
        for(int i=0;i<S.size();i++) {
            if(ss.empty()) ss.push(S[i]);
            else {
                if(S[i] == ss.top()) {
                    ss.pop();
                } else {
                    ss.push(S[i]);
                }
            }
        }

        string output = "";
        while(!ss.empty()) {
            output.push_back(ss.top());
            ss.pop();
        }

        reverse(output.begin(), output.end());
        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "abbaca";

    string result = s.removeDuplicates(str);
    cout<<result<<endl;
}