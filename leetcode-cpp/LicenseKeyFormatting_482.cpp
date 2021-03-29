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

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stack<char> v;
        for(int i=0;i<S.size();i++) {
            if (S[i] != '-') {
                v.push(S[i]);
            }
        }

        int counter = 1;
        string result="";
        while (v.size() > 0) {
            result.push_back(toupper(v.top()));
            v.pop();
            if(counter%K == 0) {
                result.push_back('-');
            }
            counter++;
        }
        reverse(result.begin(), result.end());
        if(result[0] == '-') {
            return result.substr(1);
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

    string str = "2-5g-3-J";
    int n = 2;
    string result = s.licenseKeyFormatting(str, n);
    cout<<result<<endl;
}