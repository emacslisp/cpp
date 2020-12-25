#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int numberOfMatches(int n) {
        int p = n;
        int result = 0;
        while (p > 1) {
            result += p/2;
            p = p%2 == 1? p/2+1: p/2;
        }

        return result;
    }
};

int main() {
    Solution s;
    int n;
    n = 14;
    int result = s.numberOfMatches(n);
    cout<<result<<endl;
}