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
    string freqAlphabets(string s) {
        stack<char> stack;
        for(int i=s.size() - 1;i>=0;) {
            if (s[i] == '#') {
                char c = 'a' + (s[i-2] - '0') * 10 + (s[i-1] - '0') - 1;
                stack.push(c);
                i -= 3;
            } else {
                char c = (s[i] - '1') + 'a';
                stack.push(c);
                i--;
            }
        }

        string result;
        while(stack.size() > 0) {
            result.push_back(stack.top());
            stack.pop();
        }
        return result;
    }
};

int main() {
    Solution s;

    string str = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";

    string result = s.freqAlphabets(str);
    cout<<result<<endl;
}