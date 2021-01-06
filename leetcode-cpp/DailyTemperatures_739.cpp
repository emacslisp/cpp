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
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        stack<int> stack;
        for(int i=T.size() - 1;i>=0;i--) {
            while(!stack.empty() && T[i] >= T[stack.top()]) stack.pop();
            result.push_back(stack.empty()? 0: stack.top() - i);
            stack.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       73, 74, 75, 71, 69, 72, 76, 73
    };

    string str = "codeleet";

    vector<int> result = s.dailyTemperatures(c);
    for(int x: result) {
        cout<<x<<endl;
    }
}