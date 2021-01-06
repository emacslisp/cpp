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
    int repeatedNTimes(vector<int>& A) {
        map<int, int> m;
        for(int i=0;i<A.size();i++) {
            if(m.count(A[i]) == 0) {
                m[A[i]] = 1;
            } else {
                m[A[i]] += 1;
            }
        }
        int N = A.size()/2;
        for(std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            if(it -> second == N)
            return it -> first;
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       5,1,5,2,5,3,5,4
    };

    string str = "codeleet";

    int result = s.repeatedNTimes(c);
    cout<<result<<endl;
}