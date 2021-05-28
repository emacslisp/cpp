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
    int maximumScore(int a, int b, int c) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        sort(v.begin(), v.end());

        int diff = v[2] - v[1];

        if(diff >= v[0]) {
            return v[0] + v[1];
        }
        int t = v[0] - diff;
        
        int result = diff;

        result += (v[1] - t/2 - t%2) + t;
        return result;
    }
};

int main() {
    Solution s;

    string str = "codeleet";
    int a = 3;
    int b = 4;
    int c = 6;
    int result = s.maximumScore(a, b, c);
    cout<<result<<endl;
}