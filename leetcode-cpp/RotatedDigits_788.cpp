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
    int rotated(int N, map<int, int> m) {
        int p = N;
        int result = 0;
        int offset = 1;
        while(p>0) {
            int t = p%10;
            if(m.count(t) == 0) {
                return -1;
            } else {
                t = m[t];
                result += t*offset;
            }
            p = p/10;
            offset *=10;
        }
        return result;
    }
    int rotatedDigits(int N) {
        map<int, int> m;
        m[0] = 0;
        m[1] = 1;
        m[8] = 8;
        m[2] = 5;
        m[5] = 2;
        m[6] = 9;
        m[9] = 6;

        int counter = 0;
        for(int i=1;i<=N;i++) {
            int t = rotated(i,m);
            if(t == -1) continue;
            if(t == i) continue;
            counter++;
        }
        return counter;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int n = 10000;
    int result = s.rotatedDigits(n);
    cout<<result<<endl;
}