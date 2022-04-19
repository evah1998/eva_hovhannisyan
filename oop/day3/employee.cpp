#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee(const HomoSapience& homoSapience, int salary, unsigned int workTime, unsigned int experience, bool freeFromWork)
    :HomoSapience(homoSapience)
{
	_workTime = workTime;
	_experience = experience;
    _salary = salary;
}

int countOfMonthWorkingDays = 0;
int month = 0;

void Employee::SetSalary() {
	while (countOfMonthWorkingDays < 23) {
		if (countOfMonthWorkingDays % 6 == 0 || countOfMonthWorkingDays % 7 == 0) { 
			continue;
		}
		StartWork();
	}
	GetSalary();
	++month;
	if (month == 11) {
		GoHoliday();
		++_experience;
	}
}

void Employee::SetWorkTime(const int workTime) {
	_workTime = workTime;
}

int Employee::GetSalary() const {
	return _salary;
}

void Employee::BreakTime() {
	if (_isHungry) {
		Eat(Food _food);
	}
	if (_isThirsty) {
		Drink(Drink _drink);
	}
	if (_isTired) {
		Relax();	
	}
}

void GoHoliday() {
	Relax();
}


