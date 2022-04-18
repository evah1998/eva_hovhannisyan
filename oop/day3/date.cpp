#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}

int Date::age() {
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    time_t t = time(0);
    string dateTime = ctime(&t);
    string currentMonth;
    int currentMonthNumber;
    int currentDay;
    int currentYear;
    int Age;
    string date[5] = {};
    int j = 0;
    for (int i = 0; dateTime[i] != '\0'; i++) {
        if (dateTime[i] == ' ' && dateTime[i + 1] != ' ') {
            j++;
            continue;
        }
        date[j] += dateTime[i];
    }
    for (int i = 0; i < 12; i++) {
        if (date[1] == months[i] + ' ') {
            currentMonth = months[i];
            currentMonthNumber = i + 1;
        }
    }
    currentDay = stoi(date[2]);
    currentYear = stoi(date[4]);

    Age = currentYear - _year;
    if (currentMonthNumber < _month || (currentMonthNumber == _month && currentDay < _day))
      Age--;
    return Age;
}

