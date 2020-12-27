#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.size() <= 1) return 0;

        int counter = 0;
        int result = 0;
        for(auto c : s) {
            if (c== 'R') {
                counter++;
            } else if (c=='L') {
                counter--;
            }

            if(counter == 0) {
                result++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    string str = "LLLLRRRR";

    int result = s.balancedStringSplit(str);
    cout<<result<<endl;
}