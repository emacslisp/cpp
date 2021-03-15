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

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        
        string ca = A;
        for(char c : A) {
            ca.push_back(c);
        }
        cout << ca << " " << B << endl;
        std::size_t found = ca.find(B);

        return found!=std::string::npos;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string A = "abcde";
    string B = "cdeab";
    int n = 1804289383;
    bool result = s.rotateString(A, B);
    cout<<result<<endl;
}