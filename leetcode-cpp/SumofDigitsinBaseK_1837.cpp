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
    int sumBase(int n, int k) {
        stack<int> st;
        while(n>0) {
            st.push(n%k);
            n/=k;
        }
        int sum = 0;
        while(st.size()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int n = 10;
    int k = 10;
    int result = s.sumBase(n, k);
    cout<<result<<endl;
}