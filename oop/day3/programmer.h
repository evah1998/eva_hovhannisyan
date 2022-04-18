using namespace std;
#ifndef PROGRAMMER
#define PROGRAMMER

#include "employee.h"
#include "enums.h"

class Programmer:Employee {
private:
    string _favProgrammingLanguage;
    string _company;
public:
   	Programmer(const Employee& employee, string favProgrammingLanguage, string company); 
    void WriteProgram();
};

#endif
