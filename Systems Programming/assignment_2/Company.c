/**
 * Kevin McCreary
 */
#include "Company.h"
#include "Department.h"
#include "resizer.h"
#include <string.h>
#include <stdio.h>

Company* alloc_company(){
  Company* new = malloc(sizeof(Company));
  new->noDepts = 0;
  return new;
}

void addDepartment(Company* company, Department* department){

  company->departments[company->noDepts++] = department;

}

Department* findDepartment(char deptCode, Company* company){
  for(int x = 0; x < company->noDepts; x++){
    if(&company->departments[x]->deptCode != NULL){
      if(company->departments[x]->deptCode == deptCode){
	return company->departments[x];
      }
    }
  }
  return NULL;
}
