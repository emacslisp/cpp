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
    char offset(char c, int o) {
        o = o%26;
        int a = 'z' - c;

        if(o <= a) return (char) (c + o);

        return 'a' + (o - a - 1);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        fora(i, 0 , shifts.size()) {
            shifts[i] %= 26;
        }

        int sum = 0;
        fora(i, 0, shifts.size()) {
            sum+=shifts[i];
        }

        vector<int> v(shifts.size(), 0);
        v[0] = sum;
        for(int i=1;i<v.size();i++) {
            v[i] = v[i-1] - shifts[i - 1];
        }

        string result;
        fora(i, 0, v.size()) {
            result.push_back(offset(s[i], v[i]));
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
10,16,10,26,26   };

    string str = "zvhez";
    int n = 1804289383;
    string result = s.shiftingLetters(str, c);
    cout<<result<<endl;
}