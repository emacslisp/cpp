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
    string thousandSeparator(int n) {
        string s = to_string(n);
        if(n<1000) return s;
        reverse(s.begin(), s.end());
        string result;
        int counter = 0;
        for(int i=0;i<s.size();i++) {
            result.push_back(s[i]);
            counter++;
            if(counter == 3 && i != s.size() - 1) {
                result.push_back('.');
                counter = 0;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    int n=123456789;

    string result = s.thousandSeparator(n);
    cout<<result<<endl;
}