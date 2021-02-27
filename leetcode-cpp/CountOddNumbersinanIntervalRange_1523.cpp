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
    int countOdds(int low, int high) {
        int a = (high - low + 1);

        if(a%2 == 0) {
            return a/2;
        } 

        if(low % 2 == 0) {
            return (a-1)/2;
        }

        return (a-1)/2 + 1;
    }
};

int main() {
    Solution s;
    int low, high;
    low = 3;
    high = 7;
    int result = s.countOdds(low, high);
    cout<<result<<endl;
}