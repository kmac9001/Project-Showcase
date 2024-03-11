OBJS = double_list.c test_list.c

CC = gcc

CCFLAGS = -Wall -Wpedantic -O2

LINKER_FLAGS = -lm

OBJ_NAME = test_list.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


double_list.o: help_test.c
	$(CC) -double_list.c $(CCFLAGS)
test_list.o: test_list.c
	$(CC) -test_list.c $(CCFLAGS)


clean : 
	rm main *.o *~
