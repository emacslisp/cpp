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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance = INT_MAX;
        fora(i, 0, nums.size()) {
            if (nums[i] == target) {
                int t = abs(i - start);
                if(minDistance > t) {
                    minDistance = t;
                }
            }
        }

        return minDistance;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1, 1, 1, 1, 1, 
    };

    string str = "codeleet";
    int target = 1;
    int start = 0;
    int result = s.getMinDistance(c, target, start);
    cout<<result<<endl;
}