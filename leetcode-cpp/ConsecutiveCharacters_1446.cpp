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
    int maxPower(string s) {
        int counter = 0;
        char c = '0';
        int max = 1;
        for (char x: s) {
            if (c!=x) {
                c=x;
                if(max < counter) {
                    max = counter;
                }
                counter = 1;
            } else {
                counter++;
            }
        }

        if(max < counter) {
            max = counter;
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

    string str = "aa";

    int result = s.maxPower(str);
    cout<<result<<endl;
}