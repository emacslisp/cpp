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
    int sumOfDigital(int n) {
        int p = n;
        int sum = 0;
        while(p>0) {
            sum += p%10;
            p/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, vector<int>> m;
        int maxSize = 0;
        for(int i=1;i<=n;i++) {
            int s = sumOfDigital(i);
            if(m.count(s) == 0) {
                vector<int> v;
                v.push_back(i);
                m[s] = v;
            } else {
                vector<int> v = m[s];
                v.push_back(i);
                m[s] = v;
            }

            if (maxSize < m[s].size()) {
                maxSize = m[s].size();
            }
        }

        int count = 0;
        for(auto x: m) {
            if(x.second.size() == maxSize) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";

    int n = 24;

    int result = s.countLargestGroup(n);
    cout<<result<<endl;
}