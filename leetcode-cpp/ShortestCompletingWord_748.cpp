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
    int isLetter(char s)
    {
    return ((s - 'a') >= 0&&(s - 'z') <= 0)
        ||((s - 'A') >= 0&&(s - 'Z') <= 0);
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> m;
        for(char x : licensePlate) {
            if (isLetter(x)) {
                if ((x - 'A') >= 0 && (x - 'Z') <= 0) {
                    m[x - 'A' + 'a']++;
                } else {
                    m[x]++;
                }
            }
        }

        int length = INT_MAX;
        string target = "";
        map<char, int> m1;
        for(string x : words) {
            m1.clear();
            for(char t: x) {
                m1[t]++;
            }

            bool isCompletedWord = true;
            for(auto x: m) {
                if(m1[x.first] < x.second) {
                    isCompletedWord = false;
                    break;
                }
            }

            if(isCompletedWord) {
                if (length > x.size()) {
                    length = x.size();
                    target = x;
                }
            }
        }
        return target;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "Ah71752";
    vector<string> v {
        "suggest","letter","of","husband","easy","education","drug","prevent","writer","old"
    };
    string result = s.shortestCompletingWord(str, v);
    cout<<result<<endl;
}