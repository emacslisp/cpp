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
    bool canArrange(vector<int>& arr, int k) {
        int counter = 0;
        map<int, int> m;
        for(int i=0;i<arr.size();i++) {
            int reminder = ((arr[i] %k) + k)%k;
            if(m.count(reminder) == 0) {
                m[reminder] = 1 ;
            } else {
                m[reminder]++;
            }
        }

        if(m[0] % 2 == 1) return false;

        for(auto p: m) {
            if(p.first == 0) continue;

            if(p.first == (k-p.first)%k && p.second%2 == 1) return false;

            if(m[p.first] != m[k-p.first]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       // -1,-1,-1,-1,2,2,-2,-2
       // 1,2,3,4,5,10,6,7,8,9
       -1,1,-2,2,-3,3,-4,4
    };
    int k = 3;

    string str = "codeleet";

    bool result = s.canArrange(c, k);
    cout<<result<<endl;
}