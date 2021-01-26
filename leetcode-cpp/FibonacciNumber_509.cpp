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
    int fib(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;

        vector<int> t(3, 0);
        t[0] = 1;
        t[1] = 1;

        int i = 2;
        while(i<n) {
            t[2] = t[0] + t[1];
            t[0] = t[1];
            t[1] = t[2];
            i++;
        }
        return t[2];
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int n = 6;
    int result = s.fib(n);
    cout<<result<<endl;
}