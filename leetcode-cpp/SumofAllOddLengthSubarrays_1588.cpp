#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> sums(arr.size());
        int result = 0;
        for (int i=0;i<arr.size();i++) {
            result += arr[i];
            sums[i] = result;
        }

        result = 0;
        for(int length=1;length<=arr.size();length+=2) {
            result += sums[length - 1];
            for(int i=0;i<arr.size();i+=length) {
                result += (sums[i+length] - sums[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,4,2,5,3
    };

    int result = s.sumOddLengthSubarrays(c);
    cout<<result<<endl;
}