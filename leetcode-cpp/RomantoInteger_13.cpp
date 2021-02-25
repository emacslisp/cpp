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
    int romanToInt(string s) {
        reverse(s.begin(), s.end());

        vector<char> c {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> ic {1, 5, 10, 50, 100, 500, 1000};
        map<char, int> m;

        for(int i=0;i<c.size();i++) m[c[i]] = ic[i];

        int count = 0;
        int result = 0;
        while(true) {

            if(count + 1 < s.size() && m[s[count + 1]] < m[s[count]]) {
                result += (m[s[count]] - m[s[count+1]]);
                count+=2;
            } 
            else {
                result += m[s[count]];
                count++;
            }

            if(count >= s.size()) {
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "IX";

    int result = s.romanToInt(str);
    cout<<result<<endl;
}