#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> a(n);

        for(int i=0;i<n;i++) {
            a[i] = start + 2*i;
        }

        int x = a[0];
        for(int i=1;i<n;i++) {
            x ^= a[i];
        }

        return x;
    }
};

int main() {
    Solution s;

    int n = 5;
    int start = 0;
    int result = s.xorOperation(n, start);
    cout<< result << endl;
}