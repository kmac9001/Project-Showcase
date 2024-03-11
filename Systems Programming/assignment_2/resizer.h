/**
 * Kevin McCreary
 */

#ifndef _RESIZE_H
#define _RESIZE_H

#include <stdlib.h>
#include "Employee.h"
#include "Department.h"

char* resize_char(char* str_to_re);

Employee** resize_emp(Employee** emp_to_re);

Department** resize_dep(Department** dep_to_re);

#endif
