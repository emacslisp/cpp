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
    vector<string> commonChars(vector<string>& A) {
        vector<int> v(26, 0);

        for(char c : A[0]) {
            v[c - 'a'] += 1;
        }
        for(int i=1;i<A.size();i++) {
            vector<int> t(26, 0);
            for(char c : A[i]) {
                t[c - 'a'] += 1;
            }

            for(int j=0;j<v.size();j++) {
                v[j] = Min(v[j], t[j]);
            }
        }

        vector<string> result;
        for(int j=0;j<v.size();j++) {
            if (v[j] > 0) {
                string s;
                s.push_back(j + 'a');
                for(int k=0;k<v[j];k++) {
                    result.push_back(s);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "cool","lock","cook"
    };

    string str = "codeleet";

    vector<string> result = s.commonChars(c);

    for(string x: result)
        cout<<x<<endl;
}