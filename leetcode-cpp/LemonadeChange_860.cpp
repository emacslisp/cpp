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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> left(3, 0);
        for(int x : bills) {
            if(x == 5) {
                left[0]++;
            } else if(x == 10) {
                left[1]++;
                if(left[0] <= 0) {
                    return false;
                } else
                    left[0]--;
            } else if(x == 20) {
                left[2]++;
                if(left[1] <= 0) {
                    left[0] -= 2;
                    if(left[0] <= 0)
                        return false;
                } else
                    left[1]--;
                
                if(left[0] <= 0) {
                    return false;
                } else
                    left[0]--;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       5,5,5,10,5,5,10,20,20,20
    };

    string str = "codeleet";
    int n = 1804289383;
    bool result = s.lemonadeChange(c);
    cout<<result<<endl;
}