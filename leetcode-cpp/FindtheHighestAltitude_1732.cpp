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
    int largestAltitude(vector<int>& gain) {
        vector<int> result(gain.size()+1, 0);
        int highest = 0;
        for(int i=1;i<=gain.size();i++) {
            result[i] = result[i-1] + gain[i-1];
            if(highest < result[i]) {
                highest = result[i];
            }
        }
        return highest;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       -4,-3,-2,-1,4,3,2
    };

    string str = "codeleet";

    int result = s.largestAltitude(c);
    cout<<result<<endl;
}