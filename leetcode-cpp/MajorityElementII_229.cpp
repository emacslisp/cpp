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
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int x: nums) {
            if(m.count(x) == 0) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }

        vector<int> result;
        int n = nums.size()/3;
        for(auto x: m) {
            if(x.second > n) {
                result.push_back(x.first);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1, 2
    };

    string str = "codeleet";

    vector<int> result = s.majorityElement(c);
    for(int x: result)
    cout<<x<<endl;
}