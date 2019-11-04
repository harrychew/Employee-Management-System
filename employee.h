#ifndef EMPLOYEE_CLASS_H
#define EMPLOYEE_CLASS_H

class Employee
{
public:
  employee();
  employee(int days, int workdays, double rate, double amount);
  void setmonthlyworkingdays();
  void setactualworkdays();
  void setmonthlygrossrate();
  void setsalary();
  void deleteemployeerecords();
  void listemployeerecords();
  void addemployeerecords();
  void leaveofabsence();
  void searchemployeerecord();
  void editemployeerecord();
 
private:
  int MonthlyWorkingDays;
  int ActualWorkDays;
  double MonthlyGrossRate;
  double MonthlySalary;  
};
#endif /* EMPLOYEE_CLASS_H */


