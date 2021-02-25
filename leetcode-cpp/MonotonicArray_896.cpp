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
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 1) return true;

        bool isIncreasing = true;
        for (int i=0;i<A.size() - 1;i++) {
            if(A[i] < A[i+1]) {
                isIncreasing = false;
                break;
            }
        }

        bool isDecreasing = true;
        for (int i=0;i<A.size() - 1;i++) {
            if(A[i] > A[i+1]) {
                isDecreasing = false;
                break;
            }
        }
        return isIncreasing || isDecreasing;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,4,5
    };

    string str = "codeleet";

    bool result = s.isMonotonic(c);
    cout<<result<<endl;
}