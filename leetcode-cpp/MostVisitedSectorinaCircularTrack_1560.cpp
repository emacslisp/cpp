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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> v(n+1, 0);
        rounds.push_back(rounds[rounds.size()-1] +1);
        fora(i, 0, rounds.size()-1) {
            int end = rounds[i+1];
            if(rounds[i+1] < rounds[i]) {
                end += n;
            }
            fora(j, rounds[i], end) {
                int p = j;
                p %= n;
                if(p==0) p=n;
                v[p]++;
            }
        }

        int max = 0;
        for(int x: v) {
            if(max < x) {
                max = x;
            }
        }
        
        vector<int> result;
        for(int i=1;i<v.size();i++) {
            if(v[i] == max) result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,3,5,7
    };

    string str = "codeleet";
    int n = 7;
    vector<int> result = s.mostVisited(n, c);
    for(int x: result)
        cout<<x<<endl;
}