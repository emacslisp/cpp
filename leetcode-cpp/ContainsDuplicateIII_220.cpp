#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define ll long long

using namespace std;

class tobj {
public: 
    ll value;
    ll index;

    tobj(ll value, ll index) {
        this->value = value;
        this->index = index;
    }    
};

bool cmp(tobj t1, tobj t2) {
    return t1.value < t2.value;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <= 1) return false;
        vector<tobj> v;
        for(int i=0;i < nums.size();i++) {
            tobj t(nums[i], i);
            v.push_back(t);
        }

        sort(v.begin(), v.end(), cmp);
        tobj start = v[0];
        for(int i=0;i<v.size();i++) {
            /*if(v[i].value - v[i-1].value <= t && abs(v[i].index - v[i-1].index) <= k) {
                return true;
            }*/

            int index = i+1;
            while(index< v.size() && v[index].value <= (v[i].value + t)) {
                if (abs(v[index].index - v[i].index) <= k) {
                    return true;
                }
                index++;
            }
         }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,3,6,2
    };

    string str = "codeleet";
    int k, t;
    k = 1;
    t = 1;
    bool result = s.containsNearbyAlmostDuplicate(c, k, t);
    cout<<result<<endl;
}