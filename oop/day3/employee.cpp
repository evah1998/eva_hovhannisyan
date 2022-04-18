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

void Employee::StartWork() {
	int time = 0;
	while (time <= _workTime) {
		if (time == _workTime / 2) {
			BreakTime();
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
}

void Employee::SetSalary(int salary) {
	_salary = salary;
}

int Employee::GetSalary() const {
	return _salary;
}

