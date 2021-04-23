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

class obj {
public:
    int index;
    int val;
   obj(int index, int val) {
       this->index = index;
       this->val = val;
   }
};

bool cmp(obj &o1, obj &o2) {
    return o1.val > o2.val;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<obj> v;
        map<int, string> m;
        m[0] = "Gold Medal";
        m[1] = "Silver Medal";
        m[2] = "Bronze Medal";

        fora(i,0,score.size()) {
            obj o(i, score[i]);
            v.push_back(o);
        }

        sort(v.begin(), v.end(),cmp);

        vector<string> output(score.size(), "");

        fora(i, 0, v.size()) {
            output[v[i].index] = to_string(i+1);
        }

        int size = min(3, (int)output.size());

        fora(i,0, size) {
            output[v[i].index] = m[i];
        }

        return output;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1
    };

    string str = "codeleet";
    int n = 1804289383;
    vector<string> result = s.findRelativeRanks(c);

    for(string x: result)
        cout<<x<<endl;
}