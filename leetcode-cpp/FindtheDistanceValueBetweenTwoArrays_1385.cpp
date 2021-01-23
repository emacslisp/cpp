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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        bool isMatched = true;
        int result = 0;
        for(int i=0;i<arr1.size();i++) {
            isMatched = true;
            for(int j=0;j<arr2.size();j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    isMatched = false;
                }
            }

            if (isMatched) {
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
       2,1,100,3
    };

    vector<int> c1
    {
       -5,-2,10,-3,7
    };

    int d = 6;

    int result = s.findTheDistanceValue(c, c1, d);
    cout<<result<<endl;
}