using namespace std;
#ifndef PROGRAMMER
#define PROGRAMMER

#include "homo_sapiens.h"

class Programmer:HomoSapiense {
private:
    string _favProgrammingLanguage;
    string _company;
public:
    Programmer(string surname, int year, int month, int day, string gender, string name, string fatherName, string favProgrammingLanguage, string company);
    void writeProgram();
};

#endif
