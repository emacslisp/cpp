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
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string t = "";
        while(true) {
            t+=word;
            
            if(sequence.find(t) == std::string::npos) {
                break;
            }
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "ababc";
    string word = "ab";
    int n = 1804289383;
    int result = s.maxRepeating(str, word);
    cout<<result<<endl;
}