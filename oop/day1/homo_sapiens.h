using namespace std;
#ifndef HOMO_SAPIENS
#define HOMO_SAPIENS

#include "human.h"

class HomoSapiense:Human {
private:
    string _name;
    string _fatherName;

public:
    HomoSapiense(string surname, int year, int month, int day, string gender, string name, string fatherName);
}; 

#endif
