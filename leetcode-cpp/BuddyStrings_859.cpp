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
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        int diff = 2;
        int t[26];
        
        for(int i=0;i<26;i++)
        t[i] = 0;
        vector<int> index;
        for(int i=0;i<A.size();i++) {
            if(A[i]!=B[i]) {
                diff--;
                index.push_back(i);
            }
        }

        if (diff == 0) {
            if (A[index[0]] == B[index[1]] && A[index[1]] == B[index[0]]) {
                return true;
            }
            return false;
        }
        else if(diff == 2) {
            for(int i=0;i<A.size();i++) {
                t[A[i] - 'a'] += 1;
            }
            bool hasDup = false;
            for(int i=0;i<26;i++) {
                if(t[i] >= 2) {
                    hasDup = true;
                    break;
                }
            }

            if(hasDup) return true;
            return false;
        }
        return false;
    }
};

int main() {
    Solution s;

    string A = "abcaa";
    string B = "abcbb";

    bool result = s.buddyStrings(A, B);
    cout<<result<<endl;
}