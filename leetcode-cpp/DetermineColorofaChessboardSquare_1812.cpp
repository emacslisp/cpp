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
    bool squareIsWhite(string coordinates) {
        int c = coordinates[0] - 'a';
        int r = coordinates[1] - '0';

        if(c%2 == 0) {
            if(r%2 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if(r%2 == 0) {
                return false;
            } else {
                return true;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "c7";
    int n = 1804289383;
    bool result = s.squareIsWhite(str);
    cout<<result<<endl;
}