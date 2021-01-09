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
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result;
        stack<int> stack;
        stack.push(-1);
        int max = 0;
        for(int i=arr.size()-1;i>=1;i--) {
            if(max < arr[i]) {
                max = arr[i];
            }
            stack.push(max);
        }
        while(stack.size() > 0) {
            result.push_back(stack.top());
            stack.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       400
    };

    string str = "codeleet";

    vector<int> result = s.replaceElements(c);
    for(int x: result)
        cout<<x<<endl;
}