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
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;

        int index = 0;
        int start = arr[0];
        for (int i=1;i<arr.size();i++) {
            if(arr[i]>start) {
                start = arr[i];
                continue;
            } else if (arr[i] == start) {
                return false;
            } else {
                index = i;
                break;
            }
        }

        if(start == arr[0] && index == 1) return false;

        for (int i=index;i<arr.size();i++) {
            if(arr[i]<start) {
                start = arr[i];
                continue;
            } else if (arr[i] == start) {
                return false;
            } else {
                index = i;
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       9,8,7,6,5,4,3,2,1,0
    };

    bool result = s.validMountainArray(c);
    cout<<result<<endl;
}