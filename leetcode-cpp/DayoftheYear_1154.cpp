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
    vector<string> splitByChar(string s, char c) {
        vector<string> result;
        string t;
        for(int i=0;i<s.size();i++) {
            if(s[i] != c)
                t.push_back(s[i]);
            else {
                result.push_back(t);
                t = "";
            }
        }
        result.push_back(t);
        return result;
    }
    bool isLeapYear(int year)
    {
        bool leap = false;

        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    leap = true;
                else
                    leap = false;
            }
            else
                leap = true;
        }
        else
            leap = false;

        return leap;
    }
    int dayOfYear(string date) {

        vector<int> daysOfMonth {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };

        vector<string> st = splitByChar(date, '-');

        int year = stoi(st[0]);
        int month = stoi(st[1]);
        int day = stoi(st[2]);

        int totalDays = day;

        for(int i=1;i<month;i++) {
            totalDays += daysOfMonth[i - 1];
        }

        if(month > 2 && isLeapYear(year)) {
            totalDays += 1;
        }

        return totalDays;
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "2019-02-10";
    int n = 1804289383;
    int result = s.dayOfYear(str);
    cout<<result<<endl;
}