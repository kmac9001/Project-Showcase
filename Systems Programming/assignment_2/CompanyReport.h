/**
 * Kevin McCreary
 */


#ifndef _COMPNAYREPORT_H
#define _COMPANYREPORT_H

#include "Company.h"
#include <stdio.h>

void loadDepts(FILE* input_stream, Company* company);

void loadEmps(FILE* input_stream, Company* company);

void printCompanyReport(Company* company);

#endif
