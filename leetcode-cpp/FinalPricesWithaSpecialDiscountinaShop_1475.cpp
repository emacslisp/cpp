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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        stack<int> stack;
        for(int i=prices.size() - 1;i>=0;i--) {
            while(!stack.empty() && prices[i] < prices[stack.top()]) stack.pop();
            result.push_back(stack.empty()? prices[i]: prices[i] - prices[stack.top()]);
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
       10,1,1,6
    };

    string str = "codeleet";

    vector<int> result = s.finalPrices(c);
    for(int x: result) {
        cout<<x<<endl;
    }
}