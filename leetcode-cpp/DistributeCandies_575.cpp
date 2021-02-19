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
    int distributeCandies(vector<int>& candyType) {
        map<int,int> m;
        for(int x: candyType) {
            m[x]++;
        }

        return min(m.size(), candyType.size()/2);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,1,2,3
    };

    string str = "codeleet";

    int result = s.distributeCandies(c);
    cout<<result<<endl;
}