#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    bool isPrimer(int count) {
        if(count <= 1) return false;

        for(int i = 2; i <= sqrt(count); i++) {
            if(count % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        for(int x = L ; x<=R; x++) {
            int p = x;
            int count = 0;
            while(p>0) {
                if((p & 1) == 1) count++;
                p >>= 1;
            }
            if (isPrimer(count)) {
                result++;
            }
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
    int L,R;
    L = 244;
    R = 269;
    int result = s.countPrimeSetBits(L, R);
    cout<<result<<endl;
}