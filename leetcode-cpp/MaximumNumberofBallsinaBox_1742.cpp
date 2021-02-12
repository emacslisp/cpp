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
    int sumOfDigital(int n) {
        int sum = 0;
        while(n>0) {
            sum += (n%10);
            n/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> m;
        for(int i = lowLimit;i<=highLimit;i++) {
            int s = sumOfDigital(i);
            if(m.count(s) == 0) {
                m[s] = 1;
            } else {
                m[s]++;
            }
        }
        int max = 0;
        for(auto x: m) {
            if(max < x.second) {
                max = x.second;
            }
        }
        return max;
    }
};

int main() {
    Solution s;

    int lowLimit, highLimit;
    lowLimit = 1;
    highLimit = 100000;

    int result = s.countBalls(lowLimit, highLimit);
    cout<<result<<endl;
}