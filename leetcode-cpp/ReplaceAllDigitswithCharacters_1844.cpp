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
    string replaceDigits(string s) {
        string result;
        fora(i, 0, s.size()) {
            if(s[i] - 'a' >= 0 && s[i] - 'z' <= 0) {
                result.push_back(s[i]);
            } else if(s[i] - '0' >=0 && s[i] - '9' <=0) {
                char c = result.back();
                char t= c+(s[i] - '0');
                result.push_back(t);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "a1b2c3d4e";
    int n = 1804289383;
    string result = s.replaceDigits(str);
    cout<<result<<endl;
}