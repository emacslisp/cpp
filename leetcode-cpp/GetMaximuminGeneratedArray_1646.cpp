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
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> c(n+1);
        int p = 2;
        c[0] = 0;
        c[1] = 1;
        while(p<=n) {
            if(p%2 == 0) {
                c[p] = c[p/2];
            } else {
                c[p] = c[p/2] + c[p/2+1];
            }
            p++;
        }

        int max = 0;
        for(int i=0;i<c.size();i++) {
            if(max < c[i])
            max = c[i];
        }
        return max;
    }
};

int main() {
    Solution s;
    int n = 0;

    int result = s.getMaximumGenerated(n);
    cout<<result<<endl;
}