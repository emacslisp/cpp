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
    int findSpecialInteger(vector<int>& arr) {
        int t = arr[0];
        int counter = 0;
        int boundary = arr.size()/4;
        for(int i=1;i<arr.size();i++) {
            if(t == arr[i]) {
                counter++;
            } else {
                if(counter >= boundary) {
                    return t;
                }

                counter = 0;
                t = arr[i];
            }
        }
        return t;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2, 3,4,3
    };

    int result = s.findSpecialInteger(c);
    cout<<result<<endl;
}