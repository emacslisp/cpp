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
    int sumOfUnique(vector<int>& nums) {
        map<int,int> m;
        for(int x: nums) {
            if(m.count(x) == 0) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }

        int sum = 0;
        for(auto x: m) {
            if(x.second == 1) {
                sum += x.first;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3,4,5
    };

    string str = "codeleet";

    int result = s.sumOfUnique(c);
    cout<<result<<endl;
}