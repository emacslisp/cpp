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
    int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
    int findGCDInArray(vector<int> arr) 
    { 
        int result = arr[0]; 
        for (int i = 1; i < arr.size(); i++) 
            result = gcd(arr[i], result); 
  
        return result; 
    } 
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        for(int x: deck) {
            if(m.count(x) == 0) {
                m[x] = 1;
            } else {
                m[x]++;
            }
        }
        vector<int> result;
        for (auto x: m) {
            result.push_back(x.second);
        }
        return findGCDInArray(result) >= 2;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       1,1,1,2,2,2,3,3
    };

    string str = "codeleet";

    bool result = s.hasGroupsSizeX(c);
    cout<<result<<endl;
}