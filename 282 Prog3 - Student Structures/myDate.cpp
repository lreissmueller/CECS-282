#include "myDate.h"
#include <iostream>
#include <string>

using namespace std;



int Greg2Julian(int m, int d, int y)
{
    int i = y;
    int j = m;
    int k = d;
    int JD = (k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) /
            4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 *
            ((i + 4900 + (j - 14) / 12) / 100) / 4);
    return JD;
}
void Julian2Greg(int JD, int &month, int &day, int &year)
{
    int i;
    int j;
    int k;
    int l = JD + 68569;
    int n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    year = i;
    month = j;
    day = k;
}


myDate::myDate()
{
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y)
{
    int tempDay = d;
    int tempMonth = m;
    int tempYear = y;
    int tempJulian = Greg2Julian(m, d, y);
    Julian2Greg(tempJulian, m, d, y);
    if(tempDay == d && tempMonth == m && tempYear == y)
    {
        month = m;
        day = d;
        year = y;
    }
    else
    {
        month = 5;
        day = 11;
        year = 1959;
    }

}

void myDate::display()
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

void myDate::increaseDate(int n)
{

    int jd = Greg2Julian(month, day, year);
    jd += n;
    Julian2Greg(jd, month, day, year);
}

void myDate::decreaseDate(int n)
{
    int jd = Greg2Julian(month, day, year);
    jd -= n;
    Julian2Greg(jd,month, day, year);
}

int myDate::daysBetween(myDate d)
{
    int jd = Greg2Julian(month, day, year);
    int jd1 = Greg2Julian(d.getMonth(), d.getDay(), d.getYear());
    return abs(jd - jd1);
}

int myDate::getMonth()
{
    return month;
}

int myDate::getDay()
{
    return day;
}

int myDate::getYear()
{
    return year;
}

int myDate::dayOfYear()
{
    int dayOfYear = 0;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 0; i < month - 1; i++)
    {
        dayOfYear += months[i];
    }
    dayOfYear += day;
    if((year % 4 == 0 || year % 100 == 0) && month > 2)
    {
        dayOfYear += 1;
    }
    return dayOfYear;
}

string myDate::dayName()
{
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int r = Greg2Julian(month, day, year);
    return week[r % 7];
}

string myDate::toString()
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return  months[month - 1] + " " + to_string(day) + ", " + to_string(year);
}