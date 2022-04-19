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

void Employee::StartWork() {
	_freeFromWork = false;
	int time = 0;
	while (time <= _workTime) {
		if (time == _workTime / 2) {
//			BreakTime(Food food, Drinks drink);
			++time;
			continue;
		}
		++time;
		EndWork();
	}
}

void Employee::SalaryOfMonth() {
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

void Employee::SetSalary(int salary) {
	_salary = salary;
}

int Employee::GetSalary() const {
	return _salary;
}
/*
void Employee::BreakTime(Food _food, Drink _drink) {
	Eat(_food);
	Drink(_drink);
	Relax();	
}
*/



