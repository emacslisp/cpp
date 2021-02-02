#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    vector<int> IntToArray(int K) {
        int p = K;
        vector<int> result;
        while(p>0) {
            result.push_back(p%10);
            p = p/10;
        }
        return result;
    }
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        vector<int> ka = IntToArray(K);
        vector<int> t;
        for(int i=0;i<min(A.size(),ka.size());i++) {
            t.push_back(A[i] + ka[i]);
        }

        if(A.size() > ka.size()) {
            for(int i=t.size();i<A.size();i++) {
                t.push_back(A[i]);
            }
        } else {
            for(int i=t.size();i<ka.size();i++) {
                t.push_back(ka[i]);
            }
        }

        int carry = 0;

        for(int i=0;i<t.size();i++) {
            t[i] += carry;
            if(t[i] >= 10) {
                carry = t[i]/10;
                t[i] %= 10;
            } else {
                carry = 0;
            }
        }
        if(carry > 0) {
            t.push_back(carry);
        }
        reverse(t.begin(), t.end());
        return t;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
      9,9,9,9,9,9,9,9,9,9
    };

    string str = "codeleet";
    int k = 1;
    vector<int> result = s.addToArrayForm(c, k);
    for(auto x: result)
    cout<<x<<endl;
}