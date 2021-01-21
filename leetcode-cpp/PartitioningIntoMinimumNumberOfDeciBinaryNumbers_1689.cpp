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
    int minPartitions(string n) {
        int max = 0;
        for(int i=0;i<n.size();i++) {
            int offset = n[i] - '0';
            if(max < offset) {
                max = offset;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "27346209830709182346";

    int result = s.minPartitions(str);
    cout<<result<<endl;
}