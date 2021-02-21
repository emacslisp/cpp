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
    string mergeAlternately(string word1, string word2) {
        string result;

        for(int i=0;i< min(word1.size(), word2.size());i++) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }

        if(word1.size() > word2.size()) {
            for(int i=word2.size();i<word1.size();i++) {
                result.push_back(word1[i]);
            }
        } else if (word1.size() < word2.size()) {
            for(int i=word1.size();i<word2.size();i++) {
                result.push_back(word2[i]);
            }
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

    string str1 = "abcd";
    string str2 = "pq";

    string result = s.mergeAlternately(str1, str2);
    cout<<result<<endl;
}