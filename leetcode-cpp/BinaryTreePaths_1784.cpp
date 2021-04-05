#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool checkOnesSegment(string s) {
        int start = -1;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                if(start == -1 || start == i - 1)
                    start = i;
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "110";
    int n = 1804289383;
    bool result = s.checkOnesSegment(str);
    cout<<result<<endl;
}