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
    bool compare(string s1, string s2, map<char, int> m) {
        int len = min(s1.size(), s2.size());
        fora(i, 0, len) {
            if(s1[i] == s2[i]) continue;

            if(m[s1[i]] < m[s2[i]]) {
                return true;
            } else{
                return false;
            }
        }

        if(s1.size() > s2.size()) return false;

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        int index = 0;
        for(char c: order) {
            m[c] = index++;
        }

        fora(i, 0, words.size() - 1) {
            if(!compare(words[i], words[i+1], m)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "fxasxpc","dfbdrifhp","nwzgs","cmwqriv","ebulyfyve","miracx","sxckdwzv","dtijzluhts","wwbmnge","qmjwymmyox"
    };

    string str = "zkgwaverfimqxbnctdplsjyohu";
    int n = 1804289383;
    bool result = s.isAlienSorted(c, str);
    cout<<result<<endl;
}