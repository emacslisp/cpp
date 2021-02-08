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
    
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> daysOfMonth {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        vector<string> output {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        int totalDays = 0;
        for(int i=1970;i<year;i++) {
            if(isLeapYear(i)) {
                totalDays += 366;
            } else {
                totalDays += 365;
            }
        }

        for(int i=1;i<month;i++) {
            totalDays += daysOfMonth[i - 1];
        }

        if(month > 2 && isLeapYear(year)) {
            totalDays += 1;
        }

        totalDays += day;

        // 1970, 1 and 1 is Thursday
        int offset = (3 + totalDays) % 7;
        return output[offset];
    }
};

int main() {
    Solution s;
    vector<int> c
    {
       4,5,6,7,0,2,1,3
    };

    string str = "codeleet";
    int day, month, year;
    day = 9;
    month = 2;
    year = 2021;
    string result = s.dayOfTheWeek(day, month, year);
    cout<<result<<endl;
}