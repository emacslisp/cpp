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
    int minOperations(string s) {
        int c1 =0;
        for(int i=0;i<s.size();i++) {
            if(i%2 == 0) {
                if(s[i] != '0') c1++;
            } else {
                if(s[i] != '1') c1++;
            }
        }

        int c2 = 0;
        for(int i=0;i<s.size();i++) {
            if(i%2 == 0) {
                if(s[i] != '1') c2++;
            } else {
                if(s[i] != '0') c2++;
            }
        }

        return min(c1, c2);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "0100";
    int n = 1804289383;
    int result = s.minOperations(str);
    cout<<result<<endl;
}