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
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1) return 1;
        map<int, vector<int>> m;
        map<int, vector<int>> r;

        for(vector<int> x : trust) {
            if(m.count(x[0]) > 0) {
                m[x[0]].push_back(x[1]);
            } else {
                vector<int> t;
                m[x[0]] = t;
                m[x[0]].push_back(x[1]);
            }

            if(r.count(x[1]) > 0) {
                r[x[1]].push_back(x[0]);
            } else {
                vector<int> t;
                r[x[1]] = t;
                r[x[1]].push_back(x[0]);
            }
        }

        for(int i=1;i<=N;i++) {
            if(m.count(i) == 0 && r.count(i) > 0) {
                if(r[i].size() == N-1)
                    return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> c
    {{1,3},{1,4},{2,3},{2,4},{4,3}};

    string str = "codeleet";
    int N = 4;

    int result = s.findJudge(N, c);
    cout<<result<<endl;
}