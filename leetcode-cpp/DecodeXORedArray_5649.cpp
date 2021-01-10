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
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        for(int i=0;i<encoded.size();i++) {
            result.push_back(result[result.size() - 1] ^ encoded[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       6,2,7,3
    };

    string str = "codeleet";
    int first = 4;
    vector<int> result = s.decode(c, first);
    for(int x:result)
    cout<<x<<endl;
}