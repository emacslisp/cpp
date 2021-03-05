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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        map<int, vector<char>> m;
        vector<char> t;
        t.push_back(keysPressed[0]);
        m[releaseTimes[0]] = t;
        for (int i=1;i<releaseTimes.size();i++) {
            int offset = releaseTimes[i] - releaseTimes[i-1];
            if(m.count(offset) == 0) {
                vector<char> t1;
                t1.push_back(keysPressed[i]);
                m[offset] = t1;
            } else {
                vector<char> t1 = m[offset];
                t1.push_back(keysPressed[i]);
                m[offset] = t1;
            }
        }

        int max = 0;
        for(auto x: m) {
            if(max < x.first) {
                max = x.first;
            }
        }
        
        t = m[max];
        sort(t.begin(), t.end());
        return t[t.size() - 1];
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       9,29,49,50
    };

    string str = "codeleet";
    int n = 1804289383;
    string keysPressed = "cbcd";
    char result = s.slowestKey(c, keysPressed);
    cout<<result<<endl;
}