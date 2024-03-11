/**
 * Kevin McCreary
 */


#ifndef _EMPLOYEEFILEREADER_H
#define _EMPLOYEEFILEREADER_H

#include "Employee.h"
#include <stdio.h>

Employee* readEmployee(FILE* input_stream);

char* trim_string(char* string);

float reverse_float(float to_rev);

short reverse_short(short to_rev);

#endif
