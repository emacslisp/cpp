#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

class DateTimeHelper {
public:
    bool isLeapYear(int year);
    string daysOfWeek(int day, int month, int year);
    void MainEntry();
};