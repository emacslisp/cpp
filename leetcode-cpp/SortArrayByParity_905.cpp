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
    vector<int> sortArrayByParity(vector<int>& A) {
        queue<int> even;
        queue<int> odd;

        for (int i=0;i<A.size();i++) {
            if(A[i] %2 == 0) {
                odd.push(A[i]);
            } else {
                even.push(A[i]);
            }
        }

        vector<int> result;
        while(odd.size() > 0) {
            result.push_back(odd.front());
            odd.pop();
        }

        while(even.size() > 0) {
            result.push_back(even.front());
            even.pop();
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       3
    };

    string str = "codeleet";

    vector<int> result = s.sortArrayByParity(c);

    for(int x: result)
        cout<<x<<endl;
}