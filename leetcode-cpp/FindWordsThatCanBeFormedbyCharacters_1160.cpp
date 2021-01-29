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
    int countCharacters(vector<string>& words, string chars) {
        vector<int> m(26, 0);

        for(int i=0;i<chars.size();i++) {
            m[chars[i] - 'a']++;
        }

        vector<int> n(26, 0);
        int result = 0;
        for (string t: words) {
            for(int i=0;i<26;i++) n[i] = 0;
            for(char c: t) {
                n[c - 'a']++;
            }
            bool isMatched = true;
            for (int i=0;i<26;i++) {
                if(n[i] > m[i]) {
                    isMatched = false;
                    break;
                }
            }

            if(isMatched) {
                result += t.size();
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "hello","world","leetcode"
    };

    string str = "welldonehoneyr";

    int result = s.countCharacters(c, str);
    cout<<result<<endl;
}