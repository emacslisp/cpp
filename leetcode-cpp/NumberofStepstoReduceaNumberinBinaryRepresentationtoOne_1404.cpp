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
    int numSteps(string s) {
        reverse(s.begin(), s.end());
        int p = 0;
        int steps = 0;
        while(p < s.size() - 1) {
            if(s[p] == '0') {
                steps++;
                p++;
            } else if (s[p] == '1') {
                int t = p;
                steps++;
                while(t<s.size() && s[t] == '1') {
                    t++;
                    steps++;
                }
                p = t;
                if(p < s.size() - 1)
                    s[p] = '1';
            }
        }
        return steps;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "111";

    int result = s.numSteps(str);
    cout<<result<<endl;
}