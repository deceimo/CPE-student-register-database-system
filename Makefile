#	This makefile is built to combine 7 C files to compile them together which are
#		1. mainMenu.c - show main menu of the program
#		2. display.c - show all database
#		3. addRecord.c - add new data
#		4. search.c - search the data
#		5. modify.c - modify the data
#		6. validate.c - validate the data user type
#		7. dateFunctions.c - check date in validate
#
#	Created by Nattapong Saengarunvong(Milo)	ID: 63070503415
#		16 DEC 2020


EXECUTABLES=project2

all : $(EXECUTABLES)

dateFunctions.o : dateFunctions.c
	gcc -c dateFunctions.c

validate.o : validate.c
	gcc -c validate.c

modify.o : modify.c
	gcc -c modify.c

search.o : search.c
	gcc -c search.c
	
addRecord.o : addRecord.c
	gcc -c addRecord.c
	
display.o : display.c
	gcc -c display.c
	
mainMenu.o : mainMenu.c
	gcc -c mainMenu.c

project2 : mainMenu.o display.o addRecord.o search.o modify.o validate.o dateFunctions.o
	gcc -o project2 mainMenu.o display.o addRecord.o search.o modify.o validate.o dateFunctions.o

clean :
	-rm *.o
	-rm project2
