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
    string reverseVowels(string s) {
        map<char, int> m;
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        m['A'] = 1;
        m['E'] = 1;
        m['I'] = 1;
        m['O'] = 1;
        m['U'] = 1;

        vector<char> v;
        for(char x: s) {
            if(m.count(x) > 0) {
                v.push_back(x);
            }
        }

        reverse(v.begin(), v.end());
        int index = 0;
        for(int i=0;i<s.size();i++) {
            if (m.count(s[i]) > 0) {
                s[i] = v[index++]; 
            }
        }

        return s;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "aA";
    int n = 1804289383;
    string result = s.reverseVowels(str);
    cout<<result<<endl;
}