#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0;
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                for(int k=j+1;k<arr.size();k++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                    abs(arr[j] - arr[k]) <= b &&
                    abs(arr[i] - arr[k]) <=c ) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> arr
    {
       1,1,2,2,3
    };

    int a = 0;
    int b = 0;
    int c = 1;

    int result = s.countGoodTriplets(arr, a, b, c);
    cout<<result<<endl;
}