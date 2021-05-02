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
    int score(string S, int &i) {
        stack<char> st;
        int result = 0;
        bool isContains = false;
        while(i<S.size()) {
            if(S[i] == '(' && st.size() == 1){
                result += 2*score(S, i);
                isContains = true;
            }
            else if(S[i] == '(' && st.size() == 0) {
                isContains = false;
                st.push(S[i]);
            }

            if(S[i] == ')' && st.size() == 0) {
                return result;
            }

            if(S[i] == ')' && st.size() == 1) {
                if(!isContains)
                    result += 1;
                
                st.pop();
            }

            i++;
        }

        return result;
    }
    int scoreOfParentheses(string S) {
        int offset = 0;
        return score(S, offset);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "()(())()";
    int n = 1804289383;
    int result = s.scoreOfParentheses(str);
    cout<<result<<endl;
}