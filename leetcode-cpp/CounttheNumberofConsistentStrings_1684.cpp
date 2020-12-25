#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        string s2="";
        for (string x: word1) {
            s1+=x;
        }

        for (string x: word2) {
            s2+=x;
        }

        if (s1==s2) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<string> word1 {"a", "cb"};
    vector<string> word2 {"ab", "c"};

    bool result = s.arrayStringsAreEqual(word1, word2);
    cout<< result << endl;
}