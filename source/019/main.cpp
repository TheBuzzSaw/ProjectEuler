#include <iostream>
using namespace std;

bool IsLeapYear(int year)
{
    if (year % 4) return false;
    if (year % 100) return true;
    if (year % 400) return false;
    return true;
}

int DaysInMonth(int month, int year)
{
    static const int DaysInMonths[] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (month < 1 || month > 12)
        return -1;

    if (month == 2 && IsLeapYear(year))
        return 29;
    
    return DaysInMonths[month];
}

int main(int argc, char** argv)
{
    int year = 1900;
    int month = 1;
    int dayCount = 0;
    int sundayCount = 0;
    
    while (year < 2001)
    {
        if (year > 1900 && dayCount % 7 == 6) ++sundayCount;
    
        dayCount += DaysInMonth(month++, year);
        
        if (month > 12)
        {
            month = 1;
            ++year;
        }
    }
    
    cout << sundayCount << " Sundays" << endl;
    
    return 0;
}
