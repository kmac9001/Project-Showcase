/**
 * Kevin McCreary
 */

#include "Department.h"
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Department* alloc_department(char deptCode, char* deptName, char* mgrEmpId){

  Department* dept;
  dept = malloc(sizeof(Department));

  dept->deptCode = deptCode;
  strcpy(dept->deptName, deptName);
  strcpy(dept->mgrEmpId, mgrEmpId);

  dept->noEmployees = 0;

  return dept;

}

void addEmployee(Employee* employee, Department* dept){
  
  dept->employees[dept->noEmployees++] = employee;
  
}

void set_manager(Department* dept){
  if(dept->manager == NULL){
    for(int x = 0; x < dept->noEmployees; x++){
     if(atoi(dept->employees[x]->employeeId) == atoi(dept->mgrEmpId)){
	dept->manager = dept->employees[x];
	printf("%s\n", dept->manager->firstName);
	break;
      }
    }
  }
}

int getTotalVacationDays(Department* dept){
  int totalVacationDays = 0;
  for(int x = 0; x < dept->noEmployees; x++)
    totalVacationDays += dept->employees[x]->vacationDays;

  return totalVacationDays;
}
