#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>

#define Max(a, b) a > b ? a : b
#define Min(a, b) a < b ? a : b

using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> c {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        map<char, int> m;
        for(char x: c) {
            m[x] = 1;
        }

        int first = 0;
        for(int i=0;i<s.size()/2;i++) {
            if(m[s[i]] == 1) first++;
        }

        int second = 0;
        for(int i=s.size()/2;i<s.size();i++) {
            if(m[s[i]] == 1) second++;
        }

        return first == second? true: false;
    }
};

int main() {
    Solution s;

    string str = "MerryChristmas";

    bool result = s.halvesAreAlike(str);
    cout<<result<<endl;
}