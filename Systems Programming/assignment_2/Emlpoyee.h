/**
 * Kevin McCreary
 */

/**
 * C versino of a Department of an Employee
 */

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

typedef struct {

  int month;
  int day;
  int year;

} hire_date;

typedef struct {

  char* firstName;
  char* lastName;
  char* employeeId;
  char* employeeIndicator;
  char* deptCode;
  float salary;
  hire_date* hireDate;
  short vacationDays;
  char training;

} Employee;

hire_date* alloc_hire_date(int day, int month, int year);

Employee* alloc_employee(char* employeeId, char* employeeIndicator, char* deptCode, char* firstName, char* lastName, float salary, hire_date* hireDate, short vacationDays, char training);


#endif
