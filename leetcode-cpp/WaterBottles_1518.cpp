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
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;

        int p = numBottles;
        int empty = 0;
        while(p >= numExchange) {
            result += p/numExchange;
            p = p/numExchange + p % numExchange;
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

    string str = "codeleet";
    int numBottles = 15;
    int numExchange = 4;
    int result = s.numWaterBottles(numBottles, numExchange);
    cout<<result<<endl;
}