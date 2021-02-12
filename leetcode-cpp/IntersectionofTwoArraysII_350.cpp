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
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> m1;
        map<int, int> m2;
        for(int x: nums1) m1[x]++;
        for(int x: nums2) m2[x]++;

        for(auto x: m1) {
            if(m2.count(x.first) > 0) {
                int p = min(x.second, m2[x.first]);
                for(int i=0;i<p;i++) {
                    result.push_back(x.first);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums1 {
        9,4,9,8,4
    };

    vector<int> nums2 {
        4,9,5
    };

    vector<int> result = s.intersect(nums1, nums2);

    for(int x: result)
        cout<<x<<endl;
}