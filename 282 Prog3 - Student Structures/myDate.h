// Luke Reissmueller
// CECS 282-01
// Prog 2 - myDate object
// 02/22/2021
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef MYDATE_H
#define MYDATE_H
#include <string>



using namespace std;

class myDate
{

private:
    int month;
    int day;
    int year;
public:
    myDate();
    myDate(int, int, int);
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(myDate);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    string toString();
};

int Greg2Julian(int, int, int);
void Julian2Greg(int, int &, int &, int &);

#endif
