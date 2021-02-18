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
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if(k > 0)
        for (int i=0;i<code.size();i++) {
            int sum = 0;
            for(int j=i+1;j<i+1+k;j++) {
                sum += code[j%code.size()];
            }
            result[i] = sum;
        }

        if(k < 0)
        for (int i=0;i<code.size();i++) {
            int sum = 0;
            for(int j=i-1;j>i-1+k;j--) {
                sum += code[(j+code.size())%code.size()];
            }
            result[i] = sum;
        }

        return result;
    }
    
};

int main() {
    Solution s;
    vector<int> c
    {
       2,4,9,3
    };

    int k = -2;

    vector<int> result = s.decrypt(c, k);

    for(int x: result)
        cout<<x<<endl;
}