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

bool compareInterval(int i1, int i2) 
{ 
    return abs(i1) > abs(i2); 
} 
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int counter = 0;
        int counterZero = 0;

        vector<int> v1;
        vector<int> v2;

        for(int x: A) {
            if(x < 0) {
                v1.push_back(x);
            }
            if(x == 0) counterZero++;

            if(x > 0) v2.push_back(x);
        }

        int sum = 0;
        if(K > v1.size()) {
            int t = (K - v1.size())%2;
            vector<int> vt1;
            for(int x: A) {
                    sum += abs(x);
                    vt1.push_back(abs(x));
            }

            sort(vt1.begin(), vt1.end());

            if(counterZero == 0) {
                /*sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
                sum -= min(abs(v1[v1.size() -1]), v2[0]);*/ 
                for(int i=0;i<t;i++) {
                    sum -= 2*vt1[i];
                }
            }
        } else {
            sort(v1.begin(), v1.end(), compareInterval);
            
            for(int i=0;i<v1.size();i++) {
                sum += (i<K? abs(v1[i]): v1[i]);
            }

            for(int x: v2) {
                sum += x;
            }
        }

        return sum;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -8,3,-5,-3,-5,-2
    };

    string str = "codeleet";
    int n = 6;
    int result = s.largestSumAfterKNegations(c, n);
    cout<<result<<endl;
}