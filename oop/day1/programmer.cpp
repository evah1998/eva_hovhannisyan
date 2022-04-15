#include <iostream>
#include "programmer.h"

using namespace std;

Programmer::Programmer(string surname, int year, int month, int day, string gender, string name, string fatherName, string favProgrammingLanguage, string company)
    :HomoSapiense(surname,year, month, day, gender, name, fatherName) {
    _favProgrammingLanguage = favProgrammingLanguage;
    _company = company;
}
