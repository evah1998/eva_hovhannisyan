#include <iostream>
#include "human.h"

using namespace std;

Human::Human(string surname, int year, int month, int day, string gender) {
        _surname = surname;
        _year = year;
        _month = month;
        _day = day;
        _gender = gender;
}

int Human::age() {
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

void walk() {
	int step = 0;
	step++;
}
HomoSapiense::HomoSapiense(string surname, int year, int month, int day, string gender, string name, string fatherName) 
	:Human(surname, year, month, day, gender) {
	_name = name;
	_fatherName = fatherName;
}

Programmer::Programmer(string surname, int year, int month, int day, string gender, string name, string fatherName, string favProgrammingLanguage, string company) 
	:HomoSapiense(surname,year, month, day, gender, name, fatherName) {
	_favProgrammingLanguage = favProgrammingLanguage;
	_company = company;
}

