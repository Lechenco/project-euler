#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long int ulli;
typedef struct Date {
    ulli year;
    int month;
    int day;
} Date;


static int monthsFirstDayWeek[][13] = {{-1, 1, 4, 4, 7, 2, 5, 7, 3, 6, 1, 4, 6}, 
                                    {-1, 1, 4, 5, 1, 3, 6, 1, 4, 7, 2, 5, 7}};


bool isALeapYear (ulli year) {
    if (year % 4) return false;
    else if (year % 100) return true;
    else if (year % 400) return false;
    else return true;
}

ulli nextLeapYear(ulli year) {
    do
    {
        year++;
    } while (!isALeapYear(year));
    
    return year;
}

int initialDayOfWeek(ulli year) {
    ulli currentYear = 1900;
    ulli yearsDistance = year - currentYear;

    ulli numberLeapYears = 0;
    currentYear = nextLeapYear(currentYear);
    while (currentYear < year){
        currentYear = nextLeapYear(currentYear);
        numberLeapYears++;
    }
    
    return (2 + yearsDistance + numberLeapYears) % 7;
}

void printDate(Date date) {
    cout << date.day << " " << date.month << " " << date.year << endl;
}

int zellersCongruence(Date date) {
    int K = date.year % 100;
    ulli J = date.year / 100;

    return (date.day + (int)floor(13*(date.month + 1)/5) 
        + K + (int)floor(K/4) + 5*J + (ulli)floor(J/4)) % 7;
}

void nextMonth(Date *date) {
    date->month++;
    date->month -= date->month > 12 ? 12 : 0;
    date->year += date->month == 1 ? 1 : 0;
}

bool isInitialDateBeforeFinalDate(Date initialDate, Date finalDate) {
    if (initialDate.year > finalDate.year)
        return false;
    if (initialDate.year == finalDate.year &&
        initialDate.month > finalDate.month)
        return false;
    if (initialDate.year == finalDate.year && 
        initialDate.month == finalDate.month &&
        initialDate.day > finalDate.day) return false;
    else return true;
}

int countSundays(Date initialDate, Date finalDate) {
    // prepare date
    if (initialDate.day > 1) {
        initialDate.day = 1;
        nextMonth(&initialDate);
    } 

    int count = 0;
    while (isInitialDateBeforeFinalDate(initialDate, finalDate)) {
        int dayOfWeek = zellersCongruence(initialDate);
        if (dayOfWeek == 1) {
            count++;
            printDate(initialDate);
        }
        nextMonth(&initialDate);
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while(t){
        Date initialDate;
        cin >> initialDate.year;
        cin >> initialDate.month;
        cin >> initialDate.day;

        Date finalDate;
        cin >> finalDate.year;
        cin >> finalDate.month;
        cin >> finalDate.day;

        cout << countSundays(initialDate, finalDate) << endl;
        // cout << zellersCongruence(initialDate) << endl;
        t--;
    }

    

    return 0;
}
