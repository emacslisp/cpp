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
    string maximumTime(string time) {
        if (time[4] == '?') {
            time[4] = '9';
        } 
        
        if(time[3] == '?') {
            time[3] = '5';
        } 
        
        if(time[1] == '?') {
            if(time[0] == '1' || time[0] == '0') time[1] = '9';

            if(time[0] == '2') time[1] = '3';
            if(time[0] == '?') {
                time[0] = '2';
                time[1] = '3';
            }
        } 
        
        if(time[0] == '?') {
            if(time[1]<='3') time[0] = '2';
            if(time[1] > '3') time[0] = '1';
        }
        return time;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "1?:22";

    string result = s.maximumTime(str);
    cout<<result<<endl;
}