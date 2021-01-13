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
    int minCostToMoveChips(vector<int>& position) {
        map<int,int> m;
        for(int i=0;i<position.size();i++) {
            if(m.count(position[i]) > 0) {
                m[position[i]] += 1;
            } else {
                m[position[i]] = 1;
            }
        }

        int odd = 0;
        int even = 0;
        for(std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            if(it->first % 2 == 0) {
                even+=it->second;
            } else
            {
                odd+= it->second;
            }
        }

        return odd > even? even: odd;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,1000000000
    };

    string str = "codeleet";

    int result = s.minCostToMoveChips(c);
    cout<<result<<endl;
}