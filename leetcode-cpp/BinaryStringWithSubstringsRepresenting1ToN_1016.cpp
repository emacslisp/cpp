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
    string NumberToBinary(int N) {
        int p = N;
        string output;
        while (p> 0) {
            output.push_back((char)(p%2 + '0'));
            p = p/2;
        }
        reverse(output.begin(), output.end());
        return output;
    }
    bool queryString(string S, int N) {
        
        for(int i=1;i<=N;i++) {
            if(S.find(NumberToBinary(i)) == string::npos) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "0110";
    int N = 4;
    bool result = s.queryString(str, N);
    cout<<result<<endl;
}