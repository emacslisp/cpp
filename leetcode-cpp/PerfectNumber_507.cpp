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
    bool checkPerfectNumber(int num) {
        if(num <= 1) return true;
        int sum = 1;
        for(int i=2;i<=num/2;i++) {
            if(num%i == 0) {
                sum += num/i;
            }
        }

        return num == sum;
    }
};

int main() {
    Solution s;
    int num = 2;

    bool result = s.checkPerfectNumber(num);
    cout<<result<<endl;
}