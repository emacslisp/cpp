#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        int sum = 0;
        for(int i=0;i<A.size();i++) {
            if(A[i] % 2 == 0) {
                sum += A[i];
            }
        }

        for(vector<int> x : queries) {
            int i = x[1];
            int value = x[0];
            if(A[i] % 2 == 0) {
                sum -= A[i];
            }
            A[i] += value;

            if(A[i] % 2 == 0) {
                sum += A[i];
            }
            
            result.push_back(sum);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,2,3,4
    };

    vector<vector<int>> v
    {{1,0},{-3,1},{-4,0},{2,3}};

    string str = "codeleet";
    int n = 1804289383;
    vector<int> result = s.sumEvenAfterQueries(c, v);
    for(int x: result)
        cout<<x<<endl;
}