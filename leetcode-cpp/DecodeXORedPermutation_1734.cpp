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
    vector<int> decode(vector<int>& encoded) {
        vector<int> result;
        int t = 0;
        int n = encoded.size() + 1;
        for(int i= 1;i<= n;i++) {
            t ^= i;
        }
        for(int i=1;i<encoded.size();i+=2) {
            t ^= encoded[i];
        }

        result.push_back(t);
        for(int i=0;i<encoded.size();i++) {
            int m = encoded[i] ^ result[i];
            result.push_back(m);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       6,5,4,6
    };

    string str = "codeleet";

    vector<int> result = s.decode(c);
    for(int x: result)
    cout<<x<<endl;
}