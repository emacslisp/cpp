#include "DateTimeHelper.h"

bool DateTimeHelper::isLeapYear(int year)
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

string DateTimeHelper::daysOfWeek(int day, int month, int year) {
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

void DateTimeHelper::MainEntry() {
    int year = 2016;
    DateTimeHelper s;
    bool isLeapYear = s.isLeapYear(year);
    cout << "================= DateTimeHelper =====================" <<endl; 
    cout << isLeapYear << endl;

    int day = 9, month = 2;
    year = 2021;
    cout << s.daysOfWeek(9, 2, 2021) << endl;
}