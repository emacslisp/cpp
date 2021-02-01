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
    int calPoints(vector<string>& ops) {
        vector<int> output;
        for(string s: ops) {
            if(s == "C") {
                if(output.size() > 0)
                    output.pop_back();
            } else if(s == "D") {
                if(output.size() > 0)
                    output.push_back(output[output.size() - 1] * 2);
            } else if(s == "+") {
                if(output.size() >= 2)
                    output.push_back(output[output.size() - 1] + output[output.size() - 2]);
            } else {
                output.push_back(stoi(s));
            }
        }

        int sum = 0;
        for(int i=0;i<output.size();i++) sum+=output[i];
        return sum;
    }
};

int main() {
    Solution s;
    vector<string> c
    {
       "5","2","C","D","+"
    };

    string str = "codeleet";

    int result = s.calPoints(c);
    cout<<result<<endl;
}