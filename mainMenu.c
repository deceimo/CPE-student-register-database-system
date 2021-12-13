/*****************************************************************************
*	
*	Project2
*
*	mainMenu.c
*
*	This C file is the main menu of CPE database program.It use functions from
*	3 C source files ,that can   
*		1. display current dataabase
*		2. Add new record
*		3. Search and modify current database
*
*	Created by Nattapong Saengarunvong (Milo)	ID:63070503415
*		15 DEC 2020
*
******************************************************************************/
#include<stdio.h>
#include"display.h"
#include"addRecord.h"
#include"search.h"

/*
*	Main function controls the database program.It shows main menu
*	and asks users what to do.There are four choices for users
*	1. Display current database
*	2. Add new record
*	3. Search/Modify current database
*	4. Exit the program
*/
int main()
{
	int choice=0;				//Choice in main menu
	int choice2=0;				//Choice in search database menu
	char input[32];
	
	while(1)					//Use while loop to ask users over and over
		{
		if(choice==1)			//Showing all database
			{
			showDatabase();	
			printf("\n\n\n");
			}
		else if(choice==2)		//Add all data in each one person
			{
			mainAdd();
			printf("\n\n\n");
			}
		else if(choice==3)		//Show search database menu
			{
			while(1)			//Use while loop to ask user over and over
				{
				choice2=0;
				printf("\n\n\n");
				printf("\t\t***************************************************\n");
				printf("\t\t*                                                 *\n");
				printf("\t\t*             Search Current Database             *\n");
				printf("\t\t*                                                 *\n");
				printf("\t\t*         1 - Student ID                          *\n");
				printf("\t\t*         2 - Home province                       *\n");
				printf("\t\t*         3 - Exit searching current database     *\n");
				printf("\t\t*                                                 *\n");
				printf("\t\t***************************************************\n\n");
				printf("Which one do you want to search by? ");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%d",&choice2);
				
				if(choice2==1)				//Search by using student ID
					{
					searchID();
					}
				else if(choice2==2)			//Search by using student home province
					{
					searchHomeProvince();
					}
				else if(choice2==3)			//Exit search database menu, then go back to main menu
					{
					break;
					}
				else						//Show error message if users type anything that is not 1-3
					{
					printf("\n\n\n\t\tThere are only 3 choices\n");
					printf("\t\tPlease try again\n");
					}
				}
			}
		else if(choice==4)					//Exit the program
			{
			break;
			}
		choice=0;
		printf("\t\t******************************************************\n");
		printf("\t\t*                                                    *\n");
		printf("\t\t*                CPE Student Database                *\n");
		printf("\t\t*                                                    *\n");
		printf("\t\t*            1 - Display current database            *\n");
		printf("\t\t*            2 - Add new record                      *\n");
		printf("\t\t*            3 - Search/Modify current database      *\n");
		printf("\t\t*            4 - Exit the program                    *\n");
		printf("\t\t*                                                    *\n");
		printf("\t\t******************************************************\n\n");
		printf("What do you want to do? ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&choice);
		
		if((choice>4)||(choice<1))			//If user type anything that is not 1-4, It will show error messages
			{
			printf("\n\n\n\tThere are only 4 choices\n");
			printf("\tPlease try again\n\n\n\n");
			}
		}
}
