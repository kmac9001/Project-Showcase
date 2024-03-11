/**
 * Kevin McCreary
 */

/**
 * C versino of a Department of a Company
 */

#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H

#include "Employee.h"

typedef struct _Department{

  char deptCode;
  char deptName[33];
  char mgrEmpId[33];

  Employee* employees[100];
  Employee* manager;

  int noEmployees;

} Department;

Department* alloc_department(char deptCode, char* deptName, char* mgrEmpId);

void addEmployee(Employee* employee, Department* dept);

void set_manager(Department* dept);

int getTotalVacationDays(Department* dept);

#endif
