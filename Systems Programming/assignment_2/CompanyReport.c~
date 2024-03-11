/**
 * Kevin McCreary
 */

#include "CompanyReport.h"
#include "Company.h"
#include "Department.h"
#include "DepartmentFileReader.h"
#include "Employee.h"
#include "EmployeeFileReader.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){

  Company* company;
  company = alloc_company();
  
  if(argc < 3){
    fprintf(stderr, "Usage: CompanyReport/<department file> <employee file>\n");
    exit(0);
  }

  FILE* depts_input;
  FILE* emp_input;

  depts_input = fopen(argv[1], "r");
  emp_input = fopen(argv[2], "rb");

  if(!depts_input){
    fprintf(stderr, "Departments file not found!\n");
    exit(0);
  }
  else{
    loadDepts(depts_input, company);
  }
  if(!emp_input){
    fprintf(stderr, "Employee data file not found!\n");
    exit(0);
  }
 else{
    loadEmps(emp_input, company);
  }

  printCompanyReport(company);

}

void loadDepts(FILE* input_stream, Company* company){
  Department* department;

  int cont = 1;
  while(cont){
    department = readDepartment(input_stream);
    if(department){
      addDepartment(company, department);
    }
    else{
      cont = 0;
      break;
    }
  }

}

void loadEmps(FILE* input_stream, Company* company){
  Employee* employee;

  int cont = 1;

  while(cont){
    employee = readEmployee(input_stream);
    if(employee){
      addEmployee(employee, findDepartment(employee->deptCode, company));
    }
    else
      cont = 0;
  }

}

void printCompanyReport(Company* company){
  for(int x = 0; x < company->noDepts; x++){
    set_manager(company->departments[x]);
    printf("%s Department\n", company->departments[x]->deptName);
    printf("%-20s%-10s %s\n", "Manger: ",
	   company->departments[x]->manager->firstName,
	   company->departments[x]->manager->lastName);
    printf("%-20s%-20i\n", "Staff Size: ",
	   company->departments[x]->noEmployees);
    printf("%-20s%i\n\n", "Vacation Days: ",
	   getTotalVacationDays(company->departments[x]));

    printf("%-5s %-20s %-12s %-8s %-10s\n", "ID", "Employee Name",
	   "Hire Date", "Salary", "Vac Days");

    for(int y = 0; y < company->departments[x]->noEmployees; y++){
      printf("%-5s %-10s%-10s %i/%i/%-8i $%6.2f %6i\n",
	     company->departments[x]->employees[y]->employeeId,
	     company->departments[x]->employees[y]->firstName,
	     company->departments[x]->employees[y]->lastName,
	     company->departments[x]->employees[y]->hireDate->month,
	     company->departments[x]->employees[y]->hireDate->day,
	     company->departments[x]->employees[y]->hireDate->year,
	     company->departments[x]->employees[y]->salary,
	     company->departments[x]->employees[y]->vacationDays);
    }
    printf("\n\n");
  }
}
