/**
 * Kevin McCreary
 */

/**
 * C Version of a company that maintains a list of departments
 * and has functions to access the company's departments.
 */
#ifndef _COMPANY_H
#define _COMPANY_H

#include "Department.h"

typedef struct _Company{

  Department* departments[10];
  int noDepts;

} Company;

Company* alloc_company();

/**
 * Add department to the list.
 */
void addDepartment(Company* company, Department* department);

/**
 * Find and return the specified department.
 */
Department* findDepartment(char deptCode, Company* company);

#endif
