/**********************************************************************************
*
*	addRecord.c
*
*	This C file is used to add all data in 1 CPE student.It has 6 topics of data
*	which have
*			1. Student ID
*			2. Student name
*			3. Student date of birth
*			4. Student home province
*			5. Latest GPA
*			6. Student gender
*
*	Created by Nattapong Saengarunvong(Milo)	ID:63070503415
*		16 DEC 2020
*
*	Edit to be deluxe edition on 17 DEC 2020 after passing the old one not just pass 1 hour T^T
*	I create new function that receive data from a user and write it all together
*	It will be much more better than the old version because in old version, If user
*	insert only ID and go out of the program, text file have the ID already, and
*	next time when user use it, it will get bug because there will be 2 IDs in the
*	same line. So, to prevent this situation that frequenty happens. I build this
*	function for this reason. eiei~~~~^o^
*
***********************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"validate.h"
#include"dataStruct.h"

#include"addRecord.h"



/*
*	This function ask all data from user then write them to
*	text file together
*/
void mainAdd()
{
	char ID[64];
	char title[64];
	char name[64];
	char surname[64];
	char date[64];
	char homeProvince[64];
	char GPA[16];
	char gender[32];
	FILE *pDatabase=NULL;
	
	addID(ID);
	addName(title,name,surname);
	addBirthday(date);
	addHomeProvince(homeProvince);
	addGPA(GPA);
	addGender(gender);
	
	pDatabase=fopen("database.txt","a");
	fprintf(pDatabase,"%s %s %s %s %s %s %s %c\n",ID,title,name,surname,date,homeProvince,GPA,gender[0]);
	fclose(pDatabase);
}



/*
*	addID function is used to add student ID.
*	It will ask user to insert ID then check whether
*	ID is validate or not. If it is not, it will ask
*	over and over until ID is validate. Then it will
*	check whether this ID is used before. If it is ,then
*	it will ask to insert ID again. The ID will be correct 
*	and printed in text file only if ID is valid 
*	and it is not used before.
*/
void addID(char *pID)
{
	FILE *pDatabase=NULL;						//Receive text file
	char input[128];
	char ID[64];								//Receive ID
	int result=0;								//Get result whether it is valid or not
	int line=0;									//count people in text file
	int check=0;								//Check whether ID is already used or not
	int i;										//Used as a start number in for loop
	DATA_T *student=NULL;						//Structure variable
	
	pDatabase=fopen("database.txt","r");		//Check whether text file exists or not
	
	if(pDatabase==NULL)							//If it does not exist, create new text file				
		{
		while(1)								//Loop to ask user over and over if ID is invalid
			{
			memset(ID,0,sizeof(ID));
			printf("Enter student ID:");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%s",ID);
					
			result=validateID(ID);				//Check whether ID is valid or not
			
			if(result!=1)						//If it is invalid, result will be a number that is formed
				{
				printErrorID(result);			//Print error message from each error result
				}
			else								//Otherwise, result will be 1
				{
				strcpy(pID,ID);					//Copy ID to pointer
				break;
				}
			}
		}
	else										//If text file exists, read to check whether there is any data or not
		{
		while(fgets(input,sizeof(input),pDatabase)!=NULL)
			{
			line++;
			}
		if(line==0)								//If there is no any data, start to add new data
			{
			fclose(pDatabase);					//Close text file from counting lines
			
			while(1)								//Loop to ask user over and over if ID is invalid
				{
				memset(ID,0,sizeof(ID));
				printf("Enter student ID:");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%s",ID);
					
				result=validateID(ID);				//Check whether ID is valid or not
			
				if(result!=1)						//If it is invalid, result will be a number that is formed
					{
					printErrorID(result);			//Print error message from each error result
					}
				else								//Otherwise, result will be 1
					{
					strcpy(pID,ID);					//Copy ID to pointer
					break;
					}
				}
			}
		else									//Otherwise, we will check whether ID is used or not
			{
			fclose(pDatabase);						//Close text file from counting lines
			student=calloc(line,sizeof(DATA_T));	//Allocate structure variable
			
			pDatabase=fopen("database.txt","r");	//OPen twxt file to read data
			
			for(i=0;i<line;i++)						//Reading data from text file
				{
				fgets(input,sizeof(input),pDatabase);
				sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
				}
			
			fclose(pDatabase);						//Close text file from reading data
			
			while(1)
				{
				memset(ID,0,sizeof(ID));
				printf("Enter student ID:");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%s",ID);
					
				result=validateID(ID);				//Check whether ID is valid or not
			
				if(result!=1)						//If it is invalid, result will be a number that is formed
					{
					printErrorID(result);			//Print error message from each error result
					}
				else								//Otherwise, result will be 1
					{
					check=0;						
					
					for(i=0;i<line;i++)				//Check ID is already used. If it is, check will be 1
						{
						if(strcmp(ID,student[i].ID)==0)
							{
							check=1;
							break;
							}
						}
						
					if(check==1)					//If ID is already used, it will show error message
						{
						printf("\t\tInvalid - ID:%s was already used\n",ID);
						}
					else							//Otherwise, ID will be printed in text file
						{
						strcpy(pID,ID);
						break;
						}
					}
				}
			free(student);							//Free dynamic allocation
			}
		}
}



/*
*	addName function is used to add student name with surname
*	It will ask user to insert name and check whether it is valid.
*	If it is not, it will ask over and over until it is valid
*	then print it in text file
*/
void addName(char *pTitle,char *pName,char *pSurname)
{
	char input[128];
	char title[64];										//Receive title of user
	char name[64];										//Receive name of user
	char surname[64];									//Receive name of user
	int result=0;										//Get result whether it is valid or not
	
	while(1)											//Loop to ask user over and over if title,name,or surname is invalid
		{
		memset(title,0,sizeof(title));
		printf("Enter student name:");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s %s %s",title,name,surname);
		
		result=validateName(title,name,surname);		//Check whether title ,name,or surname is valid or not
		
		if(result!=1)									//If it is invalid, result will be a number that is formed
			{
			printErrorName(result);						//Print error message from each error result
			}
		else											//Otherwise, result will be 1
			{
			properName(title,title);					//Change to be a good format
			properName(name,name);
			properName(surname,surname);
			
			strcpy(pTitle,title);
			strcpy(pName,name);
			strcpy(pSurname,surname);
			break;
			}
		}
}



/*
*	addBirthday function is used to add student date of birth.
*	It will ask user to insert date of birth and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addBirthday(char *pBirthday)
{
	char input[128];
	char date[64];											//Receive date of birth
	int result=0;											//Get result whether it is valid or not
	
	while(1)												//Loop to ask user over and over if date of birth is invalid
		{
		memset(date,0,sizeof(date));
		printf("Enter student date of birth(Buddhist year):");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",date);
		
		result=validateBirthday(date);						//check whether date of birth is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorBirthday(result);						//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			strcpy(pBirthday,date);
			break;
			}
		}
}



/*
*	addHomeProvince function is used to add student home province.
*	It will ask user to insert home province and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addHomeProvince(char *pHomeProvince)
{
	char input[128];
	char homeProvince[64];									//Receive home province
	int result=0;											//Get result whether it is valid or not
	
	while(1)												//Loop to ask user over and over if home province is invalid
		{
		memset(homeProvince,0,sizeof(homeProvince));
		printf("Enter student home province:");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",homeProvince);
		
		result=validateHomeProvince(homeProvince);			//check whether home province is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorHomeProvince(result);					//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			strcpy(pHomeProvince,homeProvince);
			break;
			}
		}
}



/*
*	addGPA function is used to add latest GPA.
*	It will ask user to insert GPA and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addGPA(char *pGPA)
{
	char input[128];
	char GPA[16];										//Receive latest GPA
	int result=0;										//Get result whether it is valid or not
	
	while(1)											//Loop to ask user over and over if GPA is invalid
		{
		memset(GPA,0,sizeof(GPA));
		printf("Enter latest GPA: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",GPA);
		
		result=validateGPA(GPA);						//check whether GPA is valid or not
		
		if(result!=1)									//If it is invalid, result will be a number that is formed
			{
			printErrorGPA(result);						//Print error message from each error result
			}
		else											//Otherwise, result will be 1
			{
			strcpy(pGPA,GPA);
			break;
			}
		}
}



/*
*	addGender function is used to add student gender.
*	It will ask user to insert gender and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addGender(char *pGender)
{
	char input[128];
	char gender[32];									//Receive gender
	int result=0;										//Get result whether it is valid or not
	
	while(1)											//Loop to ask user over and over if GPA is invalid
		{
		memset(gender,0,sizeof(gender));
		printf("Enter student gender: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",gender);
		
		result=validateGender(gender);					//check whether gender is valid or not
		
		if(result!=1)									//If it is invalid, result will be a number that is formed
			{
			printErrorGender(result);					//Print error message from each error result
			}
		else											//Otherwise, result will be 1
			{
			gender[0]=toupper(gender[0]);				//Change first letter to uppercase
			strcpy(pGender,gender);
			break;
			}
		}
}
