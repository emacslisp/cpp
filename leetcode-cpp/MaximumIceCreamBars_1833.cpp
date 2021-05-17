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
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int total = coins;

        int counter = 0;
        for (int x: costs) {
            total -=x;
            if(total >= 0)
                counter++;
            else break;
        }

        return counter;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,6,3,1,2,5
    };

    string str = "codeleet";
    int n = 20;
    int result = s.maxIceCream(c, n);
    cout<<result<<endl;
}