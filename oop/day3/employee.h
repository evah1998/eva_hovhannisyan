#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "homo_sapiens.h"
#include "enums.h"

class Employee:public HomoSapience {
  private:
      unsigned int _salary;
	  unsigned int _experience;
	  bool _freeFromWork;
	  unsigned int _workTime;
  public:
	Employee(const HomoSapience& homoSapience, int salary, unsigned int workTime, unsigned int experience, bool freeFromWork);
	Employee(const Employee&) = default;
      virtual void StartWork();
      void BreakTime();
	  virtual void EndWork();
	  virtual void Work();
	  void GoHoliday();
	  void SetWorkTime(const int workTime);
	  void SetSalary(int salary);
	  int GetSalary() const;
};

#endif 
