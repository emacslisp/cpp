#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int countHomogenous(string s) {
        int m = pow(10, 9) + 7;
        long counter = 0;
        char c = '0';
        long result = 0;
        for (char x: s) {
            if (c!=x) {
                c=x;
                result += (long)counter*(counter+1)/2;
                result %= m;
                counter = 1;
            } else {
                counter++;
            }
        }

        result += (long)counter*(counter+1)/2;

        return result%m;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "abbcccaa";

    int result = s.countHomogenous(str);
    cout<<result<<endl;
}