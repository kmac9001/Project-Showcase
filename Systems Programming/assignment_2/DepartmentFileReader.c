/**
 * Kevin McCreary
 */

#include "DepartmentFileReader.h"
#include "Department.h"
#include <stdio.h>

Department* readDepartment(FILE* input_stream){

  char deptCode = 0;
  char deptName[33];
  char mgrEmpId[33];

    int parser = 0;
    int var_parser = 0;
    char temp;
    while((temp = getc(input_stream)) != EOF){
      
      if(temp != '\n' && temp != ','){
	switch(var_parser){
	case 0:
	  deptCode = temp;
	  break;
	case 1:
	  deptName[parser] = temp;
	  parser++;
	  break;
	case 2:
	  mgrEmpId[parser] = temp;
	  parser++;
	  break;
	}
      }
      else if(temp == ','){
	switch(var_parser){
	case 0:
	  var_parser++;
	  parser = 0;
	  break;
	case 1:
	  deptName[parser] = '\0';
	  var_parser++;
	  parser = 0;
	  break;
	}
      }
      else{
	return alloc_department(deptCode, deptName, mgrEmpId);
      }	  
    }
     
     return NULL;
 
}
