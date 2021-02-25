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
    int binaryGap(int n) {
        vector<int> v;
        int p = n;
        while (p>0) {
            v.push_back(p%2);
            p >>= 1;
        }
        int distance = 0;
        int start = -1;
        for(int i=0;i < v.size();i++) {
            if(v[i] == 1) {
                start = i;
                break;                
            }
        }

        for (int i=start+1;i<v.size();i++) {
            if(v[i] == 1) {
                int d = i - start;
                if(distance < d) {
                    distance = d;
                }
                start = i;
            }
        }
        return distance;
    }
};

int main() {
    Solution s;

    int n = 1025;
    int result = s.binaryGap(n);
    cout<<result<<endl;
}