/**
 * Kevin McCreary
 */

#include "Employee.h"
#include "EmployeeFileReader.h"
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

Employee* readEmployee(FILE* input_stream){

  char employeeIdChar[4];
  char lastNameChar[16];
  char firstNameChar[21];

  int x;

  /**
   * Parse backwards to switch endianness
   */
  char temp;
 
  for(x = 0; x < (sizeof(employeeIdChar)/sizeof(char))-1; x++){
      temp = getc(input_stream);
      if(temp == EOF)
	return NULL;
    employeeIdChar[x] = temp;
  }
  employeeIdChar[3] = '\0';
  char* employeeId = employeeIdChar;

  char empIndicator = getc(input_stream);
  
  char deptCode = getc(input_stream);

  for(x = 0; x < 15; x++){
    lastNameChar[x] = getc(input_stream);
  }
  lastNameChar[15] = '\0';
  char* lastName = trim_string(lastNameChar);

for(x = 0; x < 20; x++){
    firstNameChar[x] = getc(input_stream);
  }
  firstNameChar[20] = '\0';
  char* firstName = trim_string(firstNameChar);

  float sal = 0;
  fread(&sal, 1, sizeof(float), input_stream);

  float salary = reverse_float(sal);
  
  int month = (int) getc(input_stream);
  int day = (int) getc(input_stream);
  
  short ye = 1900;
  fread(&ye, 1, sizeof(short), input_stream);

  short year = reverse_short(ye);

  hire_date* hireDate = alloc_hire_date(day, month, year);
  
  short vacD = 0;
  fread(&vacD, 1, sizeof(short), input_stream);

  short vacationDays = reverse_short(vacD);
  
  char training = getc(input_stream);
  
  Employee* employee;

  employee = alloc_employee(employeeId, empIndicator, deptCode, firstName, lastName, salary, hireDate, vacationDays, training);

  return employee;

}

char* trim_string(char* string){

  char* trimed = string;

  int l = strlen(trimed);

  while(isspace(trimed[l - 1]))
    trimed[--l] = 0;
  while(*trimed && isspace(*trimed))
    trimed++, --l;

  return strndup(trimed, l);

}

float reverse_float(float to_rev){

  float rev;

  char* f_to_rev = (char*) &to_rev;
  char* f_rev = (char*) &rev;

  f_rev[0] = f_to_rev[3];
  f_rev[1] = f_to_rev[2];
    f_rev[2] = f_to_rev[1];
      f_rev[3] = f_to_rev[0];
  
  return rev;

}


short reverse_short(short to_rev){

  short rev;

  char* s_to_rev = (char*) &to_rev;
  char* s_rev = (char*) &rev;

  s_rev[0] = s_to_rev[1];
  s_rev[1] = s_to_rev[0];
  
  return rev;

}
