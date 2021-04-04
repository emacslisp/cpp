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
    string longestNiceSubstring(string s) {
        string result ="";
        if(s.size() < 2) return result;
        int v[26];
        int v1[26];
        for(int i=0;i<s.size();i++) {
            for(int j=i+1;j<s.size();j++) {
                memset(v, 0, sizeof(int)*26);
                memset(v1, 0, sizeof(int)*26);

                for(int k=i;k<=j;k++) {
                    if(s[k]-'a' >=0 && s[k]<-'z' <=0)  {
                        v[s[k]-'a']++;
                    } else if(s[k]-'A' >=0 && s[k] <-'Z' <=0) {
                        v1[s[k]-'A']++;
                    }
                }

                bool isNice = true;
                for(int k=0;k<26;k++) {
                    if((v[k] > 0 && v1[k] >0)||
                        (v[k] == 0 && v1[k] == 0)) {
                        continue;
                    } else  {
                        isNice = false;
                        break;
                    }
                }

                if(isNice && (j-i+1) > result.size()) {
                    result.clear();
                    for(int k=i;k<=j;k++) {
                        result.push_back(s[k]);
                    }
                }
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

    string str = "dDzeE";
    int n = 1804289383;
    string result = s.longestNiceSubstring(str);
    cout<<result<<endl;
}