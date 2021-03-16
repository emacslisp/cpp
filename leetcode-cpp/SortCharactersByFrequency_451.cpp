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
    char value;
    tobj(int freq, char value) {
        this->freq = freq;
        this->value = value;
    }
};

bool cmp(tobj t1, tobj t2) {
    return t1.freq > t2.freq;
}

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char x : s) {
            m[x]++;
        }

        vector<tobj> v;
        for(auto x: m) {
            tobj t(x.second, x.first);
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);

        string result;
        for(tobj x : v) {
            for(int i=0;i<x.freq;i++) {
                result.push_back(x.value);
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

    string str = "tree";
    int n = 1804289383;
    string result = s.frequencySort(str);
    cout<<result<<endl;
}