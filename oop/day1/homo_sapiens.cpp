#include <iostream>
#include "homo_sapiens.h"

using namespace std;

HomoSapiense::HomoSapiense(string surname, int year, int month, int day, string gender, string name, string fatherName)
    :Human(surname, year, month, day, gender) {
    _name = name;
    _fatherName = fatherName;
}


