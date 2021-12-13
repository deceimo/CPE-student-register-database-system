/***************************************************************************************************
*
*	display.c
*
*	This C file is used to show all current database by reading text and count each line to know
*	how many students are in text file. Then use dynamic allocation to allocate the structure variable
*	then read text file second time to read the data in each person. Then show them all to the user.
*
*	Created by Nattapong Saengarunvong(Milo)	ID:63070503415
*		16 DEC 2020
*
***************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"dataStruct.h"

#include"display.h"

/*
*	showDatabase function shows all current database by reading text file 2 times.
*	First time is to count the lines in the text file in order to know
*	how many people in the text file. Then close it and use the number
*	of the people to allocate the structure variable. Then open text file
*	second time to read data in each line to get data in each person.
*	Then print them all.
*/
void showDatabase()
{
	FILE *pDatabase=NULL;			//receive text file
	DATA_T *student=NULL;			//Structure variable
	int line=0;						//count people in text file
	int i;							//Used as a start number in for loop
	char input[128];
	
	pDatabase=fopen("database.txt","r");	//Open text file first time for counting line
	
	if(pDatabase==NULL)			//If there is no text file, it will ask user to add new data
		{
		printf("\n\n\n\t\tThere is no any student data\n");
		printf("\t\tPlease try to add new record\n");
		}
	else						//Otherwise, we will count lines in text file
		{
		while(fgets(input,sizeof(input),pDatabase)!=NULL)		//Read and count all lines until the end of text file
			{
			line++;
			}
		
		if(line==0)				//If there is no any data in text file, it will ask user to add new data
			{
			printf("\n\n\n\t\tThere is no any student data\n");
			printf("\t\tPlease try to add new record\n");
			fclose(pDatabase);
			}
		else					//Otherwise, it will allocate the structure variable
			{
			fclose(pDatabase);								//Close text file from counting line
			student=calloc(line,sizeof(DATA_T));			//Allocate memory for structure variable
			
			pDatabase=fopen("database.txt","r");			//Open text file second time for reading all data

			for(i=0;i<line;i++)		//Read and put data into structure variable
				{
				fgets(input,sizeof(input),pDatabase);
				sscanf(input,"%s %s %s %s %s %s %f %c",student[i].ID,student[i].title,student[i].name,student[i].surname,student[i].birthday,student[i].homeProvince,&student[i].GPA,&student[i].gender);
				}
				
			for(i=0;i<line;i++)		//isplay all data from structure variable
				{
				printf("\n\n\n\t\t#Student %d\n\n",i+1);
				printf("Student ID:\t\t%s\n",student[i].ID);
				printf("Student name:\t\t%s %s %s\n",student[i].title,student[i].name,student[i].surname);
				printf("Student date of birth:\t%s\n",student[i].birthday);
				printf("Student home province:\t%s\n",student[i].homeProvince);
				printf("Latest GPA:\t\t%.2f\n",student[i].GPA);
				printf("Student gender:\t\t%c\n",student[i].gender);
				}
			fclose(pDatabase);		//Close text file from reading all data
			free(student);			//Free dynamic allocation
			}
		}
}
