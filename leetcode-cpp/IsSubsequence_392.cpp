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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(int i=0;i<t.size();i++) {
            if(t[i] == s[index]) {
                index++;
            }
        }

        return index == s.size();
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "axc";
    string t = "ahbgdc";
    bool result = s.isSubsequence(str, t);
    cout<<result<<endl;
}