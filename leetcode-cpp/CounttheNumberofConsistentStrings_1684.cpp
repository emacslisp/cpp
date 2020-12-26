#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> a(26);
        int counter = 0;
        for(int i=0;i<26;i++) {
            a[i] = 0;
        }

        for(char c: allowed) {
            a[c - 'a'] = 1;
        }

        for(string x: words) {
            bool isMatched = true;
            for(char c: x) {
                if (a[c -'a'] != 1) {
                    isMatched = false;
                    break;
                }
            }

            if (isMatched) {
                counter++;
            }
        }

        return counter;
    }
};

int main() {
    Solution s;
    vector<string> words
    {
       "a","b","c","ab","ac","bc","abc"
    };

    string allowed = "abc";

    int result = s.countConsistentStrings(allowed, words);
    cout<<result<<endl;
}