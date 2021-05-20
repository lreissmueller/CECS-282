#ifndef UPDATE_H
#define UPDATE_H
#include <string>



using namespace std;

class upDate
{

private:
    int *iptr;
    static int count;
public:
    upDate();
    upDate(int, int, int);
    upDate(int);
    upDate(const upDate &);
    ~upDate();
    int daysBetween(upDate);
    int getMonth();
    int getDay();
    int getYear();
    static int GetDateCount(); // Get date count
    string getMonthName();
    int julian();

    friend ostream & operator<<(ostream &, const upDate &);

    upDate operator=(upDate); // = operator
    upDate operator+=(int);   // += operator
    upDate operator+(int); // + operator
    int operator-(upDate); // upDate - upDate operator
    friend upDate operator+(int, upDate &); // + operator
    upDate operator-(int);   // - operator
    upDate operator++(int);  // ++ postfix operator
    upDate operator++();     // ++  prefix operator
    upDate operator--(int);  // -- postfix operator
    upDate operator--();     // -- prefix operator
    bool operator==(upDate); // == operator
    bool operator<(upDate);  // < operator
    bool operator>(upDate);  // > operator

};


int Greg2Julian(int, int, int);
void Julian2Greg(int, int &, int &, int &);

#endif
