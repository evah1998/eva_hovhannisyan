using namespace std;
#ifndef HUMAN
#define HUMAN

class Human {
private:
	string _surname;
	string _gender;
	int _year;
	int _month;
	int _day;

public:
	Human(string surname, int year, int month, int day, string gender); 
	int age();
	bool eat();
	void walk();	
};
/*
class HomoSapiense:Human {
private:
	string _name;
	string _fatherName;

public:
	HomoSapiense(string surname, int year, int month, int day, string gender, string name, string fatherName);
}; 

class Programmer:HomoSapiense {
private:
	string _favProgrammingLanguage;
	string _company;
public:
	Programmer(string surname, int year, int month, int day, string gender, string name, string fatherName, string favProgrammingLanguage, string company);
	void writeProgram();
};
*/
#endif
