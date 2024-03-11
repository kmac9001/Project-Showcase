OBJS = CompanyReport.c Company.c Department.c DepartmentFileReader.c Employee.c EmployeeFileReader.c resizer.c

CC = gcc

CCFLAGS = -Wall -Wpedantic -O2

LINKER_FLAGS = -lm

OBJ_NAME = CompanyReport.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

Employee.o: Employee.c
	$(CC) -Employee.c $(CCFLAGS)
CompanyReport.o: CompanyReport.c
	$(CC) -CompnayReport.c $(CCFLAGS)
Company.o: Company.c
	$(CC) -Company.c $(CCFLAGS)
Department.o: Department.c
	$(CC) -Department.c $(CCFLAGS)
DepartmentFileReader.o: DepartmentFileReader.c
	$(CC) -DepartmentFileReader.cs $(CCFLAGS)
EmployeeFileReader.o: EmployeeFileReader.c
	$(CC) -EmployeeFileReader.c $(CCFLAGS)
resizer.o: reizer.c
	$(CC) -resizer.c $(CCFLAGS)


clean : 
	rm main *.o *~
