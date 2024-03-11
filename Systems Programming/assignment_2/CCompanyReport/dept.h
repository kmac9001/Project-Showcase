/*
 * dept.h
 *
 * Created on: Sep 8, 2017
 * Author: dtsmith
 */

#ifndef DEPT_H_
#define DEPT_H_

#include "emp.h"

typedef struct _dept {
	char * deptName;
	char deptCode;
	int  mgrId;

	Emp *emps[100];
	int noEmps;

	Emp * manager;

} Dept;

Dept *allocDept(char *deptName, char deptCode, int mgrId);
void addEmployee(Dept * dept, Emp *emp);
Emp * getManager(Dept *dept);

// TO DO declare the prototype for any other functions corresponding to methods

#endif
