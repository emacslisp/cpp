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
    vector<string> splitByString(string s, string delim) {
        vector<string> result;
        auto start = 0U;
        auto end = s.find(delim);

        while (end != std::string::npos)
        {
            string t = s.substr(start, end - start);
            if(t!="")
                result.push_back(t);
            start = end + delim.length();
            end = s.find(delim, start);
        }

        string t = s.substr(start, end - start);
        if(t!="")
                result.push_back(t);

        return result;
    }
    int countSegments(string s) {
        vector<string> result = splitByString(s, " ");
        return result.size();
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "        ";
    int n = 1804289383;
    int result = s.countSegments(str);
    cout<<result<<endl;
}