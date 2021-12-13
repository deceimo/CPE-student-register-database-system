/*******************************************************************************************
*	
*	search.c
*	
*	This C file is used to search student in current database.It has 2 topics to be search
*	which are
*		1. ID - can be in partial match
*		2. Home province - must be all match
*
*	Created by Nattapong Saengarunvong(Milo)	ID:63070503415
*		17 DEC 2020
*
*******************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"validate.h"
#include"modify.h"
#include"dataStruct.h"


#include"search.h"

/*
*	searchID function is used to search student in current database by
*	using ID.If it matches to searched ID, it will display all data of
*	that student, and ask user to modify any data that user want.
*/
void searchID()
{
	FILE *pDatabase=NULL;					//Receive text file
	DATA_T *student=NULL;					//structure variable
	int line=0;								//count how many student in text file
	int found=0;							//count how many student ID is matched
	int *list=NULL;							//get an order of the student that ID is matched
	int i=0;								//Used as a start number in for loop
	char input[128];
	char ID[32];							//Receive searched ID
	char choice[32];						//Receive choice to modify or not
	
	pDatabase=fopen("database.txt","r");	//Open text file to count how many student in it
	if(pDatabase==NULL)						//If there is no text file, it will ask user to add new data
		{
		printf("\n\n\n\t\tThere is no any data to be searched\n");
		printf("\t\tPlease try to add new record\n");
		}
	else									//Otherwise, it will count
		{
		while(fgets(input,sizeof(input),pDatabase)!=NULL)
			{
			line++;
			}
		
		if(line==0)							//If there is no any data in text file, it will ask user to add new data
			{
			printf("\n\n\n\t\tThere is no any data to be searched\n");
			printf("\t\tPlease try to add new record\n");
			fclose(pDatabase);				//Close text file from counting people
			}
		else								//Otherwise, it will start to read data in it
			{
			fclose(pDatabase);				//Close text file from counting people
			
			student=calloc(line,sizeof(DATA_T));		//Allocate structure varible
			list=calloc(line,sizeof(int));				//Allocate a variable that gets an order of the student that ID is matched
			
			pDatabase=fopen("database.txt","r");		//Open text file to read data
			
			for(i=0;i<line;i++)
				{
				fgets(input,sizeof(input),pDatabase);
				sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
				}
			fclose(pDatabase);							//Close text file from reading data
			
			while(1)									//Loop to ask searched ID
				{
				memset(ID,0,sizeof(ID));
				printf("Enter student ID you want to search: ");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%s",ID);
				
				if(strlen(ID)==0)						//check whether user type nothing
					{
					printf("\tPlease enter student ID\n");
					}
				else if(checkAllDigits(ID)==0)			//check whether user type anything that is not a number
					{
					printf("\tPlease enter only number\n");
					}
				else									//If ID is ok, break from the loop
					{
					break;
					}
				}
				
			for(i=0;i<line;i++)							//Start to check whether there is any ID that is matched to searched ID
				{
				if(strncmp(ID,student[i].ID,strlen(ID))==0)
					{
					list[found]=i;						//Store the order of the matched ID student
					found++;							//Count how many student ID is matched
					}
				}
			
			if(found==0)			//If there is no matched student ID
				{
				printf("\n\nThere is no any student whose ID matchs with ID: %s\n",ID);
				}
			else					//Otherwise, show all data of that student that ID is matched
				{
				printf("\n\nThere are %d students whose ID match with ID: %s\n",found,ID);
				
				for(i=0;i<found;i++)
					{
					printf("\n\n\t\t#Student %d\n\n",i+1);
					printf("Student ID:\t\t%s\n",student[list[i]].ID);
					printf("Student name:\t\t%s %s %s\n",student[list[i]].title,student[list[i]].name,student[list[i]].surname);
					printf("Student date of birth:\t%s\n",student[list[i]].birthday);
					printf("Student home province:\t%s\n",student[list[i]].homeProvince);
					printf("Latest GPA:\t\t%.2f\n",student[list[i]].GPA);
					printf("Student gender:\t\t%c\n",student[list[i]].gender);
					}

				while(1)											//Loop to ask for modification
					{
					memset(choice,0,sizeof(choice));
					printf("\n\nDo you want to modify(Y/N)? ");
					fgets(input,sizeof(input),stdin);
					sscanf(input,"%s",choice);
					
					if((choice[0]=='Y')||(choice[0]=='y'))			//If user want to modify, show the modify menu
						{
						modifyMenu(list,found,line);
						break;
						}
					else if((choice[0]=='N')||(choice[0])=='n')		//If user do not want to modify, go back to search menu
						{
						break;
						}
					else											//If user type weird answer, show error message and ask again
						{
						printf("\tPlease enter either yes or no\n");
						}
					}
				}		
			free(student);				//Free dynamic allocation
			free(list);					
			}
		}
}



/*
*	searchHomeProvince function is used to search student in current database by
*	using home province.If it matches to searched home province, it will display
*	all data of that student, and ask user to modify any data that user want.
*/
void searchHomeProvince()
{
	FILE *pDatabase=NULL;							//Receive text file
	DATA_T *student=NULL;							//Structure variable
	int line=0;										//Count how many student in text file
	int found=0;									//Count how many syudent home province is matched
	int *list=NULL;									//Get an order of the student that home province is matched
	int i=0;										//Used as a start number in for loop
	char input[128];
	char homeProvince[64];							//Receive searched home province
	char choice[32];								//Receive choice to modify or not
	
	pDatabase=fopen("database.txt","r");			//Open text file to count how many student in it
	if(pDatabase==NULL)								//If there is no text file, it will ask user to add new data
		{
		printf("\n\n\n\t\tThere is no any data to be searched\n");
		printf("\t\tPlease try to add new record\n");
		}
	else											//Otherwise, it will count
		{
		while(fgets(input,sizeof(input),pDatabase)!=NULL)
			{
			line++;
			}
		
		if(line==0)									//If there is no any data in text file, it will ask user to add new data
			{
			printf("\n\n\n\t\tThere is no any data to be searched\n");
			printf("\t\tPlease try to add new record\n");
			fclose(pDatabase);						//Close text file from counting people
			}
		else										//Otherwise, it will start to read data in it
			{
			fclose(pDatabase);						//Close text file from counting people
			
			student=calloc(line,sizeof(DATA_T));	//Allocate sructure varible
			list=calloc(line,sizeof(int));			//Allocate a variable that gets an order of the student that home province is matched
			
			pDatabase=fopen("database.txt","r");	//Open text file to read data
			
			for(i=0;i<line;i++)
				{
				fgets(input,sizeof(input),pDatabase);
				sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
				}
			fclose(pDatabase);						//Close text file from read data
			
			while(1)								//Loop to ask searched home province
				{
				memset(homeProvince,0,sizeof(homeProvince));
				printf("Enter home province you want to search: ");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%s",homeProvince);
				
				if(strlen(homeProvince)==0)			//check whether user type nothing
					{
					printf("\tPlease enter home province\n");
					}
				else								//Then break from the loop
					{
					break;
					}
				}
			
			for(i=0;i<line;i++)			//Start to check whether there is any home province that is matched to the searched one
				{
				if(strcmp(homeProvince,student[i].homeProvince)==0)
					{
					list[found]=i;		//Store the order of the matched home province student
					found++;			//Count how many student ID is matched
					}
				}
			
			if(found==0)				//If there is no matched student home province
				{
				printf("\n\nThere is no any student whose home province matchs with home province: %s\n",homeProvince);
				}
			else						//Otherwise, show all data of that student that home province is matched
				{
				printf("\n\nThere are %d students whose home province match with home province: %s\n",found,homeProvince);
				
				for(i=0;i<found;i++)
					{
					printf("\n\n\t\t#Student %d\n\n",i+1);
					printf("Student ID:\t\t%s\n",student[list[i]].ID);
					printf("Student name:\t\t%s %s %s\n",student[list[i]].title,student[list[i]].name,student[list[i]].surname);
					printf("Student date of birth:\t%s\n",student[list[i]].birthday);
					printf("Student home province:\t%s\n",student[list[i]].homeProvince);
					printf("Latest GPA:\t\t%.2f\n",student[list[i]].GPA);
					printf("Student gender:\t\t%c\n",student[list[i]].gender);					
					}
				
				while(1)				//Loop to ask for modification
					{
					memset(choice,0,sizeof(choice));
					printf("\n\nDo you want to modify(Y/N)? ");
					fgets(input,sizeof(input),stdin);
					sscanf(input,"%s",choice);
					
					if((choice[0]=='Y')||(choice[0]=='y'))			//If user want to modify, show the modify menu
						{
						modifyMenu(list,found,line);
						break;
						}
					else if((choice[0]=='N')||(choice[0])=='n')		//If user do not want to modify, go back to search menu
						{
						break;
						}
					else											//If user type wierd answer, show error message and ask again
						{
						printf("\tPlease enter either yes or no\n");
						}
					}
				}
			free(student);				//Free dynamic allocation
			free(list);
			}		
		}
}
