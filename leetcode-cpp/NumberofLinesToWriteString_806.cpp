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
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum = 0;
        int line = 1;
        for(int i=0;i<s.size();i++) {
            sum += widths[s[i] - 'a'];

            if(sum== 100) {
                line++;
                sum = 0;
            }

            if(sum>100) {
                sum = widths[s[i] - 'a'];
                line++;
            }
        }

        if (sum == 0) {
            line--;
            sum = 100;
        }
        vector<int> result;
        result.push_back(line);
        result.push_back(sum);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
    };

    string str = "bbbcccdddaaa";

    vector<int> result = s.numberOfLines(c, str);
    for(int x : result)
        cout<<x<<endl;
}