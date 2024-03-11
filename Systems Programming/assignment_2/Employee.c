/**
 * Kevin McCreary
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Employee.h"

hire_date* alloc_hire_date(int day, int month, int year){
  hire_date* hiring_date;
  hiring_date = malloc(sizeof(hire_date));

  hiring_date->day = day;
  hiring_date->month = month;
  hiring_date->year = year;

  return hiring_date;

}

Employee* alloc_employee(char* employeeId, char employeeIndicator, char deptCode, char* firstName, char* lastName, float salary, hire_date* hireDate, short vacationDays, char training){

  Employee* emp = malloc(sizeof(Employee));
  strcpy(emp->employeeId , employeeId);

  emp->employeeIndicator = employeeIndicator;
  emp->deptCode = deptCode;
  
  strcpy(emp->firstName , firstName);
  strcpy(emp->lastName , lastName);
  emp->salary = salary;
  emp->hireDate = hireDate;
  emp->vacationDays = vacationDays;
  emp->training = training;

  return emp;

}
