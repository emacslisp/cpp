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
    int maximum69Number (int num) {
        int p = num;
        stack<int> stack;
        while(p>0) {
            stack.push(p % 10);
            p = p/10;
        }

        bool isGet = true;
        int result = 0;
        while(stack.size() > 0) {
            int a = stack.top();
            if(a == 6 && isGet) {
                a = 9;
                isGet = false;
            }
            result = 10*result + a;
            stack.pop();
        }

        return result;
    }
};

int main() {
    Solution s;
    int num = 9996;

    int result = s.maximum69Number(num);
    cout<<result<<endl;
}