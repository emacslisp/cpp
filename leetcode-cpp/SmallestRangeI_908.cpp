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
    int smallestRangeI(vector<int>& A, int K) {
        int max = INT_MIN;
        int min = INT_MAX;

        for (int i=0;i<A.size();i++) {
            if(max < A[i]) {
                max = A[i];
            }

            if(min > A[i]) {
                min = A[i];
            }
        }

        max -= K;
        min += K;

        if(max < min) return 0;

        return max - min;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,3,6
    };

    string str = "codeleet";
    int k = 3;

    int result = s.smallestRangeI(c, k);
    cout<<result<<endl;
}