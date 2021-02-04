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

    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        
        int p = N;
        int result = 0;
        vector<int> v;
        while(p>0) {
            int x = p & 1;
            v.push_back(x == 0? 1: 0);
            p >>= 1;
        }
        int m = 1;
        for(int x: v) {
            result += m*x;
            m <<=1;
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
    int N = 1000000000;
    int result = s.bitwiseComplement(N);
    cout<<result<<endl;
}