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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto x: matrix) {
            for(int t : x) {
                q.push(t);
            }
        }

        while(k>1) {
            q.pop();
            k--;
        }
        return q.top();
    }
};

int main() {
    Solution s;
    vector<vector<int> > c
    {{1,5,9},{10,11,13},{12,13,15}};

    string str = "codeleet";
    int n = 8;
    int result = s.kthSmallest(c, n);
    cout<<result<<endl;
}