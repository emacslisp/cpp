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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        char t = s[0];
        int counter = 1;
        int start = 0;
        int end = 0;
        s.append(to_string(0));
        vector<vector<int>> result;
        for(int i=1;i<s.size();i++) {
            if(s[i] == t) {
                counter++;
            } else {
                end = i-1;
                vector<int> t1;
                if(end - start >= 2) {
                    t1.push_back(start);
                    t1.push_back(end);
                    result.push_back(t1);
                }
                
                t = s[i];
                counter = 1;
                start = i;
                end = i;
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

    string str = "aaa";
    int n = 1804289383;
    vector<vector<int>> result = s.largeGroupPositions(str);
    for(auto x : result) {
        for(auto y: x) {
            cout << y << endl;
        }
    }
}