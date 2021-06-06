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
#define ld long double
#define fora(i, start, end) for(int i=start;i<end;i++)
#define forb(i, start, end) for(int i=end;i>=start;i--)
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9+7;
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))


class Solution {
public:
    int getValue(string str) {
        int result = 0;
        int index = 1;
        for(int i = str.size() - 1;i>=0;i--) {
            result += (str[i] - 'a') * index;
            index *= 10;
        }

        return result;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getValue(firstWord) + getValue(secondWord) == getValue(targetWord);
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "aaa";
    string str2 = "a";
    string target = "aab";
    bool result = s.isSumEqual(str, str2, target);
    cout<<result<<endl;
}