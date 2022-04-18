#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "homo_sapiens.h"
#include "enums.h"

class Employee:public HomoSapience {
  private:
      unsigned int _salary = 9;
	  unsigned int _workTime;
	  unsigned int _experience;
	  bool _freeFromWork;
  public:
	Employee(const HomoSapience& homoSapience, int salary, unsigned int workTime, unsigned int experience, bool freeFromWork);
	Employee(const Employee&) = default;
      void StartWork();
      void BreakTime();
	  virtual void EndWork();
	  void SalaryOfMonth();
	  virtual void Work();

	  void GoHolyday();

	  void SetSalary(int salary);
	  int GetSalary() const;
};

#endif 
