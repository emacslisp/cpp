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

class tobj {
    public:
    int freq;
    int value;
    tobj(int freq, int value) {
        this->freq = freq;
        this->value = value;
    }
};

bool cmp(tobj t1, tobj t2) {
    return t1.freq > t2.freq;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int x: nums) {
            m[x]++;
        }

        vector<tobj> v;
        for(auto x: m) {
            tobj t(x.second, x.first);
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);

        vector<int> result;
        for(int i=0;i<k;i++) {
            result.push_back(v[i].value);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,1,-1,2,-1,2,3
    };

    string str = "codeleet";
    int n = 2;
    vector<int>  result = s.topKFrequent(c, n);
    for(int x: result)
    cout<<x<<endl;
}