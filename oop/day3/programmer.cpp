#include <iostream>
#include "programmer.h"

using namespace std;
	Programmer::Programmer(const Employee& employee, string favProgrammingLanguage, string company)
	:Employee(employee)
{
    _favProgrammingLanguage = favProgrammingLanguage;
    _company = company;
}
