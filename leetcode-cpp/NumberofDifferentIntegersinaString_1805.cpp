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
    string removeZero(string n) {
        string filter = "";
        int index = 0;
        while(n[index++] == '0') {
            
        }
        for(int i=index-1;i<n.size();i++) {
            filter.push_back(n[i]);
        }
        return filter;
    }
    int numDifferentIntegers(string word) {
        string n = "";
        map<string, int> m;
        for (char x : word) {
            if(x - '0' >= 0 && x-'0' <= 9) {
                n.push_back(x);
            } else {
                if(n.size() > 0) {
                    string nz = removeZero(n);
                    m[nz]++;
                    n.clear();
                }
            }
        }

        if(n.size() > 0) {
            string nz = removeZero(n);
            m[nz]++;
            n.clear();
        }
        return m.size();
    }
};

int main() {
    Solution s;
    string str = "4w31am0ets6sl5go5ufytjtjpb7b0sxqbee2blg9ss";
    int result = s.numDifferentIntegers(str);
    cout<<result<<endl;
}