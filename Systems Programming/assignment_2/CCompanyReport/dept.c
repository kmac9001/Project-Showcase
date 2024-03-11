/*
 * dept.c
 *
 * Created on: Sep 8, 2017
 * Author: dtsmith
 */
#include <stdlib.h>

#include "dept.h"

Dept *allocDept(char *deptName, char deptCode, int mgrId) {
	Dept *dept = malloc(sizeof(Dept));
	dept->deptName = deptName;
	dept->deptCode = deptCode;
	dept->mgrId = mgrId;
	dept->noEmps = 0;
	dept->manager = NULL;
	return dept;
}

void addEmployee(Dept * dept, Emp *emp) {
	dept->emps[dept->noEmps++] = emp;
}

Emp * getManager(Dept *dept) {
	if (dept->manager == NULL) {
		for (int i = 0; i < dept->noEmps; i++) {
			Emp *emp = dept->emps[i];
			if (emp->empId == dept->mgrId) {
				dept->manager = emp;
				break;
			}
		}
	}

	return dept->manager;
}

// TO DO declare the prototype for any other functions corresponding to methods
