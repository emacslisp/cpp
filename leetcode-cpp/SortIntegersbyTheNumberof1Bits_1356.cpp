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
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> main(32, vector<int>());

        for(int x: arr) {
            int p = x;
            int counter = 0;
            while(p>0) {
                if ((p & 1) == 1) counter++;
                p>>=1;
            }
            main[counter].push_back(x);
        }

        vector<int> result;
        for(int i=0;i<main.size();i++) {
            vector<int> t = main[i];
            sort(t.begin(), t.end());
            for(int x: t) {
                result.push_back(x);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,3,5,7,11,13,17,19
    };

    string str = "codeleet";

    vector<int> result = s.sortByBits(c);
    for(int x : result)
        cout<<x<<endl;
}