/*****************************************************************************************
*
*	modify.c
*
*	This C file is used to modify data in the current database.It has 6 topics of modification
*	which are
*		1. Student ID
*		2. Student name
*		3. Student date of birth
*		4. Student home province
*		5. GPA
*		6. Student gender
*
*	Created by Nattapong Saengarunvong(Milo)	ID:63070503415
*		17 DEC 2020
*
*****************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"validate.h"
#include"dataStruct.h"


#include"modify.h"



/*
*	modifyMenu function control modification of the data
*	It ask user what topic to modify.There are 6 topics
*	to modify which are
*		1. Student ID
*		2. Student name
*		3. Student date of birth
*		4. Student home province
*		5. GPA
*		6. Student gender
*	and there are 3 arguments.
*	First is list of student that is matched.
*	Second is the number of matched student.
*	Third is the numver of the students in text file
*/
void modifyMenu(int list[],int found,int line)
{
	char input[128];
	char number[32];				//Number of students that is matched
	int choice;						//choose which student to be modified
	int topic=0;					//Choose modified topic
	
	if(found>1)				//If there are more than 1 matched student, ask user which student user want to modified 
		{
		while(1)
			{
			memset(number,0,sizeof(number));
			printf("Enter a number of the student you want to modify: ");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%s",number);
			
			if(strlen(number)==0)						//Check whether user type nothing
				{
				printf("\tPlease enter a number of the student you want to modify\n");
				}
			else if(checkAllDigits(number)==0)			//Check whether user type anthing that is not number
				{
				printf("\tPlease enter only number\n");
				}
			else
				{
				sscanf(number,"%d",&choice);
				
				if((choice<1)||(choice>found))			//Check user choose out of a list student
					{
					printf("\tThere are only %d students\n",found);
					}
				else
					{
					break;
					}
				}
			}
		}
	else if(found==1)		//If there is 1 matched student, choice must be 1
		{
		choice=1;
		}

	while(1)				//Loop ask user what topic user wants to modify
		{
		topic=0;
		printf("\n\n");
		printf("\t\t******************************************\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*              Modified topic            *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*          1. Student ID                 *\n");
		printf("\t\t*          2. Student name               *\n"); 
		printf("\t\t*          3. Student date of birth      *\n");
		printf("\t\t*          4. Student home province      *\n");
		printf("\t\t*          5. GPA                        *\n");
		printf("\t\t*          6. Student gender             *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t******************************************\n\n");
		printf("What topic do you want to modify? ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&topic);

		if(topic==1)
			{
			modifyID(list,choice,line);
			break;
			}
		else if(topic==2)
			{
			modifyName(list,choice,line);
			break;
			}
		else if(topic==3)
			{
			modifyBirthday(list,choice,line);
			break;
			}
		else if(topic==4)
			{
			modifyHomeProvince(list,choice,line);
			break;
			}
		else if(topic==5)
			{
			modifyGPA(list,choice,line);
			break;
			}
		else if(topic==6)
			{
			modifyGender(list,choice,line);
			break;
			}
		else
			{
			printf("\n\n\tThere are only 6 choices\n");
			printf("\tPlease try again\n");
			}
		}
}



/*
*	modifyID function is used to modify ID by
*	asking user to type new ID then check whether
*	ID is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyID(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");				//Open text file to read data
	DATA_T student[line];									//Structure variable
	char ID[64];											//Receive new ID
	int check;												//Receive whether ID is already used
	int i;													//Used as a start number in for loop
	int result;												//Get result whether it is valid or not
	
	for(i=0;i<line;i++)										//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
		}
	fclose(pDatabase);									//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");				//Open text file to write all data down
	
	while(1)											//Loop to ask user over and over if ID is invalid
		{
		memset(ID,0,sizeof(ID));
		printf("Enter new student ID:");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",ID);
		
		result=validateID(ID);							//Check whether ID is valid or not
		
		if(result!=1)									//If it is invalid, result will be a number that is formed
			{
			printErrorID(result);						//Print error message from each error result
			}
		else											//Otherwise, result will be 1
			{
			check=0;
			
			for(i=0;i<line;i++)							//Check whether ID is already used
				{
				if(i != list[choice-1])					//Check every ID execpt itself
					{
					if(strcmp(ID,student[i].ID)==0)
						{
						check=1;
						break;
						}
					}
				}
			if(check==1)								//If ID is already used
				{
				printf("\t\tInvalid - ID:%s was already used\n",ID);
				}
			else										//Otherwise, copy new ID to the old one, then write all data to text file
				{
				strcpy(student[list[choice-1]].ID,ID);
				
				for(i=0;i<line;i++)
					{
					fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
					}
				fclose(pDatabase);						//Close text file from writing all data
				break;
				}
			}	
		}
}



/*
*	modifyName function is used to modify name by
*	asking user to type new name then check whether
*	name is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyName(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");			//Open text file to read data
	DATA_T student[line];								//Structure variable
	char title[64];										//Receive new title
	char name[64];										//Receive new name
	char surname[64];									//Receive new surname
	int check;											//Receive whether title,name,or surname is valid or not
	int i;												//Used as a start number in for loop
	int result;											//Get result whether it is valid or not
	
	for(i=0;i<line;i++)									//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
		}
	fclose(pDatabase);									//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");				//Open text file to write all data down
	
	while(1)											//Loop to ask user over and over if name is invalid
		{
		memset(title,0,sizeof(title));
		printf("Enter new student name:");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s %s %s",title,name,surname);
		
		result=validateName(title,name,surname);		//Check whether name is valid or not
		
		if(result!=1)									//If it is invalid, result will be a number that is formed
			{
			printErrorName(result);						//Print error message from each error result
			}
		else											//Otherwise, result will be 1
			{
			properName(title,title);					//Change to be a good format
			properName(name,name);
			properName(surname,surname);
			
			strcpy(student[list[choice-1]].title,title);	//Copy new one to the old one, then write all data to text file
			strcpy(student[list[choice-1]].name,name);
			strcpy(student[list[choice-1]].surname,surname);
			
			for(i=0;i<line;i++)
				{
				fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
				}
			fclose(pDatabase);							//Close text file from writing all data
			break;
			}
		}
}



/*
*	modifyBirthday function is used to modify date of birth by
*	asking user to type new data of birth then check whether
*	date of birth is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyBirthday(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");				//Open text file to read data
	DATA_T student[line];									//Structure variable
	char date[64];											//Receive new date of birth
	int check;												//Receive whether data of birth is valid or not
	int i;													//Used as a start number in for loop
	int result;												//Get result whether it is valid or not
	
	for(i=0;i<line;i++)										//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);		
		}
	fclose(pDatabase);										//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");					//Open text file to write all data down
	
	while(1)												//Loop to ask user over and over if date of birth is invalid
		{
		memset(date,0,sizeof(date));
		printf("Enter new student date of birth(Buddhist year):");
		fgets(input,sizeof(input),stdin);

		sscanf(input,"%s",date);
		
		result=validateBirthday(date);						//Check whether date of birth is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorBirthday(result);						//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			strcpy(student[list[choice-1]].birthday,date);	//Copy new one to the old one, then write all data to text file
			
			for(i=0;i<line;i++)
				{
				fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
				}
			fclose(pDatabase);								//Close text file from writing all data
			break;
			}
		}
}



/*
*	modifyHomeProvince function is used to modify home province by
*	asking user to type new home province then check whether
*	home province is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyHomeProvince(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");				//Open text file to read data
	DATA_T student[line];									//Structure variable
	char homeProvince[64];									//Receive new home province
	int check;												//Receive whether home province is valid or not
	int i;													//Used as a start number in for loop
	int result;												//Get result whether it is valid or not
	
	for(i=0;i<line;i++)										//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);		
		}
	fclose(pDatabase);										//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");					//Open text file to write all data down
	
	while(1)												//Loop to ask user over and over if home province is invalid
		{
		memset(homeProvince,0,sizeof(homeProvince));
		printf("Enter new student home province:");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",homeProvince);
		
		result=validateHomeProvince(homeProvince);			//Check whether home province is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorHomeProvince(result);					//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			strcpy(student[list[choice-1]].homeProvince,homeProvince);	//Copy new one to the old one, then write all data to text file
			for(i=0;i<line;i++)
				{
				fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
				}
			fclose(pDatabase);								//Close text file from writing all data
			break;
			}		
		}	
}



/*
*	modifyGPA function is used to modify GPA by
*	asking user to type new GPA then check whether
*	GPA is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyGPA(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");				//Open text file to read data
	DATA_T student[line];									//Structure variable
	char GPA[16];											//Receive new GPA
	float gpa;												//Change GPA from char to float datatype
	int check;												//Receive whether GPA is valid or not
	int i;													//Used as a start number in for loop
	int result;												//Get result whether it is valid or not
	
	for(i;i<line;i++)										//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);		
		}
	fclose(pDatabase);										//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");					//Open text file to write all data down

	while(1)												//Loop to ask user over and over if GPA is invalid
		{
		memset(GPA,0,sizeof(GPA));
		printf("Enter new latest GPA: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",GPA);
		
		result=validateGPA(GPA);							//Check whether GPA is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorGPA(result);							//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			sscanf(GPA,"%f",&gpa);							//Change GPA from char to float
			student[list[choice-1]].GPA = gpa;				//Copy new one to the old one, then write all data to text file

			for(i=0;i<line;i++)
				{
				fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
				}
			fclose(pDatabase);								//Close text file from writing all data
			break;
			}
		}
}



/*
*	modifyGender function is used to modify gender by
*	asking user to type new gender then check whether
*	gender is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyGender(int list[],int choice,int line)
{
	char input[128];
	FILE *pDatabase=fopen("database.txt","r");				//Open text file to read data
	DATA_T student[line];									//Structure variable
	char gender[32];										//Receive new gender
	int check;												//Receive whether gender is valid or not
	int i;													//Used as a start number in for loop
	int result;												//Get result whether it is valid or not
	
	for(i=0;i<line;i++)										//Read all data
		{
		fgets(input,sizeof(input),pDatabase);
		sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
		}
	fclose(pDatabase);										//Close text file from reading data
	
	pDatabase=fopen("database.txt","w");					//Open text file to write all data down
	
	while(1)												//Loop to ask user over and over if gender is invalid
		{
		memset(gender,0,sizeof(gender));
		printf("Enter new student gender: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",gender);
		
		result=validateGender(gender);						//Check whether gender is valid or not
		
		if(result!=1)										//If it is invalid, result will be a number that is formed
			{
			printErrorGender(result);						//Print error message from each error result
			}
		else												//Otherwise, result will be 1
			{
			gender[0]=toupper(gender[0]);					//Change first letter to be uppercase
			student[list[choice-1]].gender = gender[0];		//Copy new one to the old one, then write all data to text file
			
			for(i=0;i<line;i++)
				{
				fprintf(pDatabase,"%s %s %s %s %s %s %f %c\n",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,student[i].GPA,student[i].gender);
				}
			fclose(pDatabase);								//Close text file from writing all data
			break;
			}
		}
}
