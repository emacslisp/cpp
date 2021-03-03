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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> m;
        m["type"] = 0;
        m["color"] = 1;
        m["name"] = 2;

        int count = 0;
        for(vector<string> v : items) {
            if(v[m[ruleKey]] == ruleValue) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<vector<string>> c
    {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};

    string ruleKey = "type", ruleValue = "phone";

    int result = s.countMatches(c, ruleKey, ruleValue);
    cout<<result<<endl;
}