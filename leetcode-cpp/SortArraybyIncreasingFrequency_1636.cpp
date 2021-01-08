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
    bool cmp(pair<int, int>& a, 
            pair<int, int>& b) 
    { 
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second; 
    } 

class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> result;
        map<int,int> map;
        for(int i=0;i<nums.size();i++) {
            if(map.count(nums[i]) > 0) {
                map[nums[i]] += 1;
            } else {
                map[nums[i]] = 1;
            }
        }

        for (auto& it: map) {
            result.push_back(it);
        }

        sort(result.begin(), result.end(), cmp);

        vector<int> output;
        for(pair<int, int> a: result) {
            for(int i=0;i<a.second;i++) {
                output.push_back(a.first);
            }
        }
        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,3,1,3,2
    };

    string str = "codeleet";

    vector<int> result = s.frequencySort(c);
    for(int x: result)
        cout<<x<<endl;
}