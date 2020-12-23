#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = n;

        int add = 0;
        int mul = 1;
        while(p>0) {
            add += p%10;
            mul *= p%10;
            p /= 10;
        }

        return mul - add;
    }
};

int main() {
    Solution s;

    int n = 234;
    int result = s.subtractProductAndSum(n);
    cout<< result << endl;
}