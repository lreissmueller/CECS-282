// Luke Reissmueller
// CECS 282-01
// Prog 4 - Operator Overloading
// 04/5/2021
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


#include "upDate.h"
#include <iostream>
#include <string>

using namespace std;

int upDate::count = 0;

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


upDate::upDate()
{
    iptr = new int[3];
    iptr[0] = 5;
    iptr[1] = 11;
    iptr[2] = 1959;
    count+=1;
}

upDate::upDate(int m, int d, int y)
{
    iptr = new int[3];
    int tempDay = d;
    int tempMonth = m;
    int tempYear = y;
    int tempJulian = Greg2Julian(m, d, y);
    Julian2Greg(tempJulian, m, d, y);
    if(tempDay == d && tempMonth == m && tempYear == y)
    {
        iptr[0] = m;
        iptr[1] = d;
        iptr[2] = y;
    }
    else
    {
        iptr[0] = 5;
        iptr[1] = 11;
        iptr[2] = 1959;
    }
    count+=1;
}
upDate::upDate(const upDate & d) // copy constructor
{
    iptr = new int[3];
    iptr[0] = d.iptr[0];
    iptr[1] = d.iptr[1];
    iptr[2] = d.iptr[2];
    count+=1;
}
upDate::~upDate()
{
    delete[] iptr;
    count-=1;
}
upDate::upDate(int J)
{
    iptr = new int[3];
    if (J < 0)
    {
        iptr[0] = 5;
        iptr[1] = 11;
        iptr[2] = 1959;
    }
    else
    {
        Julian2Greg(J, iptr[0], iptr[1], iptr[2]);
    }
    count+=1;
}

int upDate::daysBetween(upDate d)
{
    int jd = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    int jd1 = Greg2Julian(d.getMonth(), d.getDay(), d.getYear());
    return abs(jd - jd1);
}

int upDate::getMonth()
{
    return iptr[0];
}

int upDate::getDay()
{
    return iptr[1];
}

int upDate::getYear()
{
    return iptr[2];
}

// getMonthName
string upDate::getMonthName()
{
    string m[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int r = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    return m[r % 7];
}
// =

// <<
ostream & operator<<(ostream & out, const upDate & d)
{
    out << d.iptr[0] << "/" << d.iptr[1] << "/" << d.iptr[2];
    return out;
}
// +=
upDate upDate::operator+=(int n)
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    j += n;
    Julian2Greg(j, iptr[0], iptr[1], iptr[2]);
    return *this;
}
upDate upDate::operator+(int n)  // + operator int second
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    j+=n;
    int month = iptr[0];
    int day = iptr[1];
    int year = iptr[2];
    Julian2Greg(j, month, day, year);
    return upDate(month, day, year);
}
int upDate::operator-(upDate d) // upDate - upDate operator
{
    return this->julian() - d.julian();
}
upDate operator+(int n, upDate &date)  // + operator object second
{
    int j = Greg2Julian(date.iptr[0], date.iptr[1], date.iptr[2]);
    j+=n;
    int month = date.iptr[0];
    int day = date.iptr[1];
    int year = date.iptr[2];
    Julian2Greg(j,month, day, year);
    return upDate(month, day, year);
}
upDate upDate::operator=(upDate d) // = operator
{
    iptr[0] = d.iptr[0];
    iptr[1] = d.iptr[1];
    iptr[2] = d.iptr[2];
    return *this;
}
int upDate::julian()
{
    return Greg2Julian(iptr[0], iptr[1], iptr[2]);
}
upDate upDate::operator-(int n)  // - operator
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    j-=n;
    int month = iptr[0];
    int day = iptr[1];
    int year = iptr[2];
    Julian2Greg(j, month, day, year);
    return upDate(month, day, year);
}
upDate upDate::operator++(int)  // ++ postfix operator
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    j++;
    Julian2Greg(j, iptr[0], iptr[1], iptr[2]);
    return upDate(iptr[0], iptr[1], iptr[2]);
}
upDate upDate::operator++()   // ++  prefix operator
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    ++j;
    Julian2Greg(j, iptr[0], iptr[1], iptr[2]);
    return upDate(iptr[0], iptr[1], iptr[2]);
}
upDate upDate::operator--(int)   // --  postfix operator
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    j--;
    Julian2Greg(j, iptr[0], iptr[1], iptr[2]);
    return upDate(iptr[0], iptr[1], iptr[2]);
}
upDate upDate::operator--()   // --  prefix operator
{
    int j = Greg2Julian(iptr[0], iptr[1], iptr[2]);
    --j;
    Julian2Greg(j, iptr[0], iptr[1], iptr[2]);
    return upDate(iptr[0], iptr[1], iptr[2]);
}
bool upDate::operator==(upDate d) // == operator
{
    if (this->julian() == d.julian())
    {
        return true;
    }
    return false;
}
bool upDate::operator<(upDate d)
{
    if(this->julian() < d.julian())
    {
        return true;
    }
    return false;
}
bool upDate::operator>(upDate d)
{
    if(this->julian() > d.julian())
    {
        return true;
    }
    return false;
}

int upDate::GetDateCount() // Get date count
{
    return count;
}
