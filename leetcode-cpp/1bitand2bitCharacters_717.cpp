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
     bool isOneBitCharacter(vector<int>& bits) {
        fora(i, 0, bits.size()) {
            if(bits[i] == 1) {
                i+=1;
                continue;
            } else if(bits[i] == 0) {
                if(i == bits.size() - 1) return true;

                continue;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1, 1, 1, 0, 0
    };

    string str = "codeleet";
    int n = 1804289383;
    bool result = s.isOneBitCharacter(c);
    cout<<result<<endl;
}