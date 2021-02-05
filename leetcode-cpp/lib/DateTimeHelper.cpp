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

void DateTimeHelper::MainEntry() {
    int year = 2016;
    DateTimeHelper s;
    bool isLeapYear = s.isLeapYear(year);
    cout << "================= DateTimeHelper =====================" <<endl; 
    cout << isLeapYear << endl;
}