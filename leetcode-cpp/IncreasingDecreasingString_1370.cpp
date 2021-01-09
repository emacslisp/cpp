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

bool cmp(pair<char, int>& a, 
            pair<char, int>& b) 
    { 
        return a.first < b.first;
    } 

class Solution {
public:
    string sortString(string s) {
        map<char, int> map;

        for(int i=0;i<s.size();i++) {
            if(map.count(s[i]) > 0) {
                map[s[i]] += 1;
            } else {
                map[s[i]] = 1;
            }
        }

        vector<pair<char, int>> result;
        for (auto& it: map) {
            result.push_back(it);
        }

        sort(result.begin(), result.end(), cmp);

        int counter = 0;
        string output;
        while (true) {
            for(int i=0;i<result.size();i++) {
                pair<char,int> *t = &result[i];
                if(t->second > 0) {
                    output.push_back(t->first);
                    t->second -= 1;
                    counter++;
                }
            }

            for(int i=result.size() - 1;i>=0;i--) {
                pair<char,int> *t = &result[i];
                if(t->second > 0) {
                    output.push_back(t->first);
                    t->second -= 1;
                    counter++;
                }
            }

            if(counter >= s.size()) {
                break;
            }
        }

        return output;
    }
};

int main() {
    Solution s;

    string str = "a";

    string result = s.sortString(str);
    cout<<result<<endl;
}