#include <iostream>
#include "myDate.h"
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;
struct Student
{
    char name[25];
    int ID;
    char grade;
    string homeTown;
    myDate birthday;
};
int randomID()
{
    return (rand() % 1000)  + 9000;
}
char randomGrade()
{
    char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    return grades[rand() % 5];
}
myDate randomBDay()
{
    myDate day(1, 1, 1995);
    day.increaseDate(rand() % 4017);
    return day;
}
void *populate(Student* s_ptr)
{
    myDate day;
    s_ptr[10];
    string homeTowns[10] = {"Harlem", "Staffordshire", "Hamilton", "Irvine", "North Shore",

                            "Bloomington","Pasadena", "Lafayette", "Frankfurt", "Long Beach"};
    for(int i = 0; i < 10; i++)
    {
        int id = randomID();
        s_ptr[0].ID = randomID();
        for(int j = 0; j < i; j++)
        {
            if(s_ptr[j].ID != id)
            {
                s_ptr[i].ID = id;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        s_ptr[i].grade = randomGrade();
        s_ptr[i].homeTown = homeTowns[i];
        s_ptr[i].birthday = randomBDay();
    }
    strcpy(s_ptr[0].name, "Tom Morello");
    strcpy(s_ptr[1].name, "Slash Hudson");
    strcpy(s_ptr[2].name, "Neil Peart");
    strcpy(s_ptr[3].name, "Zach Rocha");
    strcpy(s_ptr[4].name, "Jack Johnson");
    strcpy(s_ptr[5].name, "David Lee Roth");
    strcpy(s_ptr[6].name, "Eddie Van Halen");
    strcpy(s_ptr[7].name, "Axl Rose");
    strcpy(s_ptr[8].name, "Tre Cool");
    strcpy(s_ptr[9].name, "Bradley Nowell");
}
void swap(Student *s, Student *s1)
{
    Student temp = *s;
    s = s1;
    *s1 = temp;
}
void display(Student* s)
{
    cout << setw(25) << "Name" << setw(10) << "\tStudent ID" << setw(5) << "\tGrade\t" << setw(20) << "Birthday\t" << setw(15) << "Home Town" << endl;
    cout << setw(25) << "-----" << setw(10) << "\t----------" << setw(5) << "\t-----\t" << setw(20) << "--------\t" << setw(15) << "---------" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << setw(25) << s[i].name << "\t" << setw(10) << s[i].ID << "\t" << setw(5) << s[i].grade << "\t" << setw(20)
        << s[i].birthday.toString() << "\t" << setw(15) << s[i].homeTown << endl;
    }
    cout << "\n\n";
}

void sortByName(Student* s)
{
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++) {
            if (strcmp(s[i].name, s[j].name) > 0) {
                swap(s[i], s[j]);
            }
        }
    }
}

void sortByGrade(Student* s)
{
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++) {
            if (s[i].grade > s[j].grade) {
                swap(s[i], s[j]);
            }
        }
    }
}

void sortByID(Student* s)
{
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++) {
            if (s[i].ID > s[j].ID) {
                swap(s[i], s[j]);
            }
        }
    }
}
void sortByBirthday(Student* s)
{
    int jd1 = 0;
    int jd2 = 0;
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++) {
            jd1 = Greg2Julian(s[i].birthday.getMonth(), s[i].birthday.getDay(),s[i].birthday.getYear());
            jd2 = Greg2Julian(s[j].birthday.getMonth(), s[j].birthday.getDay(),s[j].birthday.getYear());
            if (jd1 > jd2) {
                swap(s[i], s[j]);
            }
        }
    }
}
void sortByHometown(Student* s)
{
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++) {
            if (s[i].homeTown > s[j].homeTown) {
                swap(s[i], s[j]);
            }
        }
    }
}
void menu(Student s[])
{
    string input;
    cout << "1) Display list sorted by Name\n2) Display list sorted by Student ID\n3) Display list sorted by "
            "Grade\n4) Display list sorted by Birthday\n5) Display list sorted by Home Town\n6) Exit" << endl;
    cin >> input;

    if (input == "1")
    {
        cout << "Sorting by name...\n";
        sortByName(s);
        display(s);
        menu(s);
    }
    else if (input == "2")
    {
        cout << "Sorting by ID...\n";
        sortByID(s);
        display(s);
        menu(s);
    }
    else if (input == "3")
    {
        cout << "Sorting by grade...\n";
        sortByGrade(s);
        display(s);
        menu(s);
    }
    else if (input == "4")
    {
        cout << "Sorting by birthday...\n";
        sortByBirthday(s);
        display(s);
        menu(s);
    }
    else if (input == "5")
    {
        cout << "Sorting by hometown...\n";
        sortByHometown(s);
        display(s);
        menu(s);
    }
    else if (input == "6")
    {
        cout << "Exited." << endl;
    }
}

int main() {

    Student s[10];
    Student *s_ptr = s;
    populate(s_ptr);
    menu(s);
    return 0;
}
