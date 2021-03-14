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
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int sumA = 0;
        int sumB = 0;
        map<int, int> m;
        for(int x: A) {
            sumA+=x;
        }
        for(int x: B) {
            sumB+=x;
            m[x] = 1;
        }

        int avg = (sumA+sumB)/2;

        for(int i=0;i<A.size();i++) {
            if(avg >= (sumA - A[i])) {
                int targetB = (avg - (sumA - A[i]));
                if(m.count(targetB) == 1) {
                    result.push_back(A[i]);
                    result.push_back(targetB);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A
    {
       1, 2, 5
    };

    vector<int> B
    {
       2, 4
    };

    string str = "codeleet";
    int n = 1804289383;
    vector<int> result = s.fairCandySwap(A, B);

    for(int x: result)
        cout<<x<<endl;
}