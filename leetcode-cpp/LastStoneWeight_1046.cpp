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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int x: stones) {
            q.push(x);
        }
        int l1 = q.top();
        q.pop();
        while(!q.empty()) {
            int l2 = q.top();
            q.pop();
            if(l1 == l2) {
                if (!q.empty()) {
                    l1 = q.top();
                    q.pop();
                } else {
                    return 0;
                }
            } else {
                q.push(abs(l1-l2));
                l1 = q.top();
                q.pop();
            }
            
        }
        return l1;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       2,7,4,1,8,1
    };

    int result = s.lastStoneWeight(c);
    cout<<result<<endl;
}