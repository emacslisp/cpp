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
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        for(int x: nums) {
            m[x]++;
        }

        vector<int> result;
        for(int i=1;i<=nums.size();i++) {
            if(m[i] > 1) result.push_back(i);
        }
        
        for(int i=1;i<=nums.size();i++) {
            if(m[i] == 0) result.push_back(i);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,2
    };

    string str = "codeleet";
    int n = 1804289383;
    vector<int> result = s.findErrorNums(c);
    for(int x: result)
        cout<<x<<endl;
}