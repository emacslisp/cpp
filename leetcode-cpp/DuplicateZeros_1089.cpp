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
    void duplicateZeros(vector<int>& arr) {
        vector<int> index;
        for(int i = arr.size()-1;i>=0;i--) {
            if(arr[i] == 0) {
                index.push_back(i);
            }
        }

        for(int i: index) {
            arr.insert(arr.begin() + i, 0);
            arr.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,0,2,3,0,4,5,0
    };

    string str = "codeleet";

    s.duplicateZeros(c);
    for(int x: c)
    cout<<x<<endl;
}