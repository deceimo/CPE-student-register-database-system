/*******************************************************************************
*
*	validate.c	
*
*	This C file is used to gather functions that validate each of the data which
*	have 6 topics that are
*		1. ID
*		2. Name
*		3. Date of birth
*		4. Home province
*		5. GPA
*		6. Gender
*	Created by Nattapong Saengarunvong(Milo)	ID:63070503415
*		17 DEC 2020
*
********************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"dateFunctions.h"

#include"validate.h"


/*
This function validate student ID.If ID is valid
,then function will send back value 1.But if ID
is invalid, it will send back other value that
is up to what is invalid
*/
int validateID(char ID[])
{
	int result=0;
	
	if(strlen(ID)!=11)				//Check whether ID length is 11 digits or not
		{
		result=2;
		}
	else if(checkAllDigits(ID)==0)	//Check whether ID is a number or not
		{
		result=3;
		}
	else if(checkMiddleID(ID)==0)	//Check whether third to seventh digit are 07050 or not
		{
		result=4;
		}
	else if(checkLastID(ID)==0)		//Check whether last two digits is not 00 or not
		{
		result=5;
		}
	else if(checkFrontID(ID)==0)	//Check whether first two digits is between 55 to 63 or not
		{
		result=6;
		}
	else if(checkProgramID(ID)==0)	//Check whether eighth and ninth is 34 or 10 or not
		{
		result=7;
		}
	else
		{
		result=1;
		}
	return result;
}

//These functions are used in validateID.

/*
This function checks whether ID is all the numbers or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkAllDigits(char stringToCheck[])
{
	int start=0;
	int test;
	int length=strlen(stringToCheck);
	
	for(start=0;start<length;start++)
		{
		if(isdigit(stringToCheck[start]))
			{
			test=1;
			}
		else
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function checks whether third to seventh digit are 07050 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkMiddleID(char stringToCheck[])
{
	int test;
	int start=0;
	char middle[]={'0','7','0','5','0'};
	
	for(start=0;start<5;start++)
		{
		if(middle[start]==stringToCheck[start+2])
			{
			test=1;					
			}
		else
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function checks whether last two digits is not 00 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkLastID(char stringToCheck[])
{
	int test;
	if((stringToCheck[9]=='0')&&(stringToCheck[10])=='0')
		{
		test=0;
		}
	else
		{
		test=1;
		}
	return test;
}

/*
This function checks whether first two digits is between 55 to 63 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkFrontID(char stringToCheck[])
{
	int test;
	if((stringToCheck[0]!='5')&&(stringToCheck[0]!='6'))
		{
		test=0;
		}
	else if((stringToCheck[0]=='5')&&(stringToCheck[1]<'5'))
		{
		test=0;
		}
	else if((stringToCheck[0]=='6')&&(stringToCheck[1]>'3'))
		{
		test=0;
		}
	else
		{
		test=1;
		}
	return test;
}

/*
This function checks whether eighth and ninth is 34(International)
or 10(Regular) or not.If it is,it will send back value 1 to validateCPE_ID
;Otherwise,it will send back value 0
*/
int checkProgramID(char stringToCheck[])
{
	int test;
	if((stringToCheck[7]=='3')&&(stringToCheck[8]=='4'))
		{
		test=1;
		}
	else if((stringToCheck[7]=='1')&&(stringToCheck[8]=='0'))
		{
		test=1;
		}
	else
		{
		test=0;
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorID(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknown error\n");
			break;
		case 2:
			printf("\t\tInvalid - ID must be 11 digits\n");
			break;
		case 3:
			printf("\t\tInvalid - ID must be only number\n");
			break;
		case 4:
			printf("\t\tInvalid - ID must have 07050 in the middle\n");
			break;
		case 5:
			printf("\t\tInvalid - Last two ID digits must not be 00\n");
			break;
		case 6:
			printf("\t\tInvalid - First two ID digits must be between 55 to 63\n");
			break;
		case 7:
			printf("\t\tInvalid - Digit 8 and 9 must be either 34 or 10\n");
			break;
		}			
}






/*
This function validate student name.If name is valid
,then function will send back value 1.But if name
is invalid, it will send back other value that
is up to what is invalid
*/
int validateName(char title[],char name[],char surname[])
{
	int result=0;
	
	if(checkTitle(title)==0)				//Check whether title is Mr. Mrs. Miss Ms.
		{
		result=2;
		}
	else if(checkNameLength(name)==0)		//Check whether name length is between 2-30
		{
		result=3;
		}
	else if(checkNameLength(surname)==0)	//Check whether surname length is between 2-30
		{
		result=3;
		}
	else if(checkAlphabet(name)==0)			//Check whether name has only alphbet
		{
		result=4;
		}
	else if(checkAlphabet(surname)==0)		//Check whether surname has only alphabet
		{
		result=4;
		}
	else
		{
		result=1;
		}
	return result;
}

/*
This function check whether title is only
Mr. Mrs. Ms. Miss or not.If it is,it will send
back value 1;Otherwise,it will send value 0
*/
int checkTitle(char stringToCheck[])
{
	char title[4][16]={"Mr.","Mrs.","Miss","Ms."};
	int length=0;
	int test=0;
	int start=0;
	
	for(start=0;start<4;start++)
		{
		if(strcasecmp(stringToCheck,title[start])==0)
			{
			test=1;
			break;
			}
		}

	return test;
}

/*
This function check whether string length is between
2-30 or not.If it is, it will return value 1;Otherwise,
it will send back value 0
*/
int checkNameLength(char stringToCheck[])
{
	int length=strlen(stringToCheck);
	int test=1;
	
	if((length<2)||(length>30))
		{
		test=0;
		}
	return test;
}

/*
This function check whether string has only alphabet
or not.If it is, it will return value 1;Otherwise,
it will send back value 0
*/
int checkAlphabet(char stringToCheck[])
{
	int length=strlen(stringToCheck);
	int test=1;
	int start=0;
	
	for(start=0;start<length;start++)
		{
		if(isalpha(stringToCheck[start])==0)
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorName(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknown error\n");
			break;
		case 2:
			printf("\t\tInvalid - Title must be Mr.,Mrs.,Miss,or Ms.\n");
			break;
		case 3:
			printf("\t\tInvalid - Name and surname's length must be 2-30 characters long\n");
			break;
		case 4:
			printf("\t\tInvalid - Name and surname must be only alphabet\n");
			break;
		}
}

/*
This function receive string to modify by
changing first letter to be uppercase, and
other letter to be lowercase. It has 2 arguments
First is the string to be modified
Second is the modified string
*/
void properName(char string[],char *newString)
{
	int length=strlen(string);
	int start;
	
	string[0]=toupper(string[0]);
	
	for(start=1;start<length;start++)
		{
		string[start]=tolower(string[start]);
		}
	
	strcpy(newString,string);	
}











/*
This function validate student date of birth.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateBirthday(char date[])
{
	int result=0;
	
	if(strlen(date)!=10)		//Check whether length of date is 10 character or not
		{
		result=2;
		}
	else if((date[2]!='/')||(date[5]!='/'))		//Check whether delimiter is slash or not
		{
		result=3;
		}
	else if(checkAllNumber(date)==0)			//Check whether date is a number or not
		{
		result=4;
		}
	else if(checkDateMonthYear(date)==1)		//These check proper day,month,and year
		{
		result=5;
		}
	else if(checkDateMonthYear(date)==2)
		{
		result=6;
		}
	else if(checkDateMonthYear(date)==3)
		{
		result=7;
		}
	else if(checkDateMonthYear(date)==4)
		{
		result=8;
		}
	else if(checkDateMonthYear(date)==5)
		{
		result=9;
		}
	else if(checkDateMonthYear(date)==6)
		{
		result=10;
		}
	else if(checkDateMonthYear(date)==7)
		{
		result=11;
		}
	else if(checkFuture(date)==0)				//Check date is not in the future
		{
		result=12;
		}
	else
		{
		result=1;
		}
	return result;
}


//These functions are used in validateBirthday

/*
This function checks whether date that user type has alphabets or not
If there is any alphabet in date,it will send value 0 back to validate Date
function;Otherwise,it will send value 1
*/
int checkAllNumber(char stringToCheck[])
{
	int test;
	int start;
	int arrayNum[8]={0,1,3,4,6,7,8,9};
	
	for(start=0;start<8;start++)
		{
		if(isdigit(stringToCheck[arrayNum[start]]))
			{
			test=1;
			}
		else
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function checks correstness of day,month,and year
If there is nothing wrong,it will send value 8 back to 
validate date function;Otherwise,it will send 
values 1 to 8 by its invalidation
*/
int checkDateMonthYear(char stringToCheck[])
{
	int day=0;
	int month=0;
	int year=0;
	int test=0;
	sscanf(stringToCheck,"%d/%d/%d",&day,&month,&year);
	
	if((day>31)||(day<1))				//Check whether day is between 1 to 12 or not
		{
		test=1;
		}
	else if((month>12)||(month<1))		//Check whether month is between 1 to 12 or not
		{
		test=2;
		}
	else if((year>2663)||(year<2463))	//Check whether year is between 2463 to 2663 or not
		{
		test=3;
		}
	else if(checkMonthMax30Day(month)&&(day==31))		//Check whether month has a max 30 days and day is 31 or not
		{
		test=4;
		}
	else if((day>29)&&(month==2)&&(((year-543)%4)!=0))	//Check whether day is more than 29,month is February,and it is not a leap year or not
		{
		test=5;
		}
	else if((day>29)&&(month==2)&&(((year-543)%4)==0))	//Check whether day is more than 29,month is February,and it is a leap year or not
		{
		test=6;
		}
	else if((day==29)&&(month==2)&&(((year-543)%4)!=0))	//Check whether day is 29,month is February,and it is not a leap year or not
		{
		test=7;
		}
	else
		{
		test=8;
		}
	return test;
}

/*
This function checks month of the user whether
it is a month that has only 30 days or not.
If it is,it will send value 1 back to validate date function
;Otherwise,it will send value 0
*/
int checkMonthMax30Day(int monthToCheck)
{
	int month30Day[]={4,6,9,11};
	int start=0;
	int test;
	for(start=0;start<4;start++)
		{
		if(monthToCheck==month30Day[start])
			{
			test=1;
			break;
			}
		else
			{
			test=0;
			}
		}
	return test;
}

/*
This function checks whether date is in the future or not.
If it is,it will send back value 0.But if it is not,it will
send back value 1
*/
int checkFuture(char stringToCheck[])
{
	int test=1;
	int compare;
	int dayToday;
	int monthToday;
	int yearToday;
	int dayInput;
	int monthInput;
	int yearInput;
	
	dateToday(&dayToday,&monthToday,&yearToday);
	
	yearToday=yearToday+543;
	
	sscanf(stringToCheck,"%d/%d/%d",&dayInput,&monthInput,&yearInput);
	
	compare=dateCompare(dayInput,monthInput,yearInput,dayToday,monthToday,yearToday);
	
	if(compare!=-1)
		{
		test=0;
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorBirthday(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknown error\n");
			break;
		case 2:
			printf("\t\tInvalid - Input must be in form dd/mm/yyyy\n");
			break;
		case 3:
			printf("\t\tInvalid - Delimiter must be /\n");
			break;
		case 4:
			printf("\t\tInvalid - Day,month and year must be a number\n");
			break;
		case 5:
			printf("\t\tInvalid - Day must be between 1 to 31\n");
			break;
		case 6:
			printf("\t\tInvalid - Month must be between 1 to 12\n");
			break;
		case 7:
			printf("\t\tInvalid - Year must be between 2463 to this year\n");
			break;
		case 8:
			printf("\t\tInvalid - This month has only 30 days\n");
			break;
		case 9:
			printf("\t\tInvalid - Month 2 has only 28 days\n");
			break;
		case 10:
			printf("\t\tInvalid - Month 2 has only 29 days in a leap year\n");
			break;
		case 11:
			printf("\t\tInvalid - This year is not a leap yaer\n");
			break;
		case 12:
			printf("\t\tInvalid - Birthday must be in the past\n");
			break;
		}
}








/*
This function validate student home province.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateHomeProvince(char homeProvince[])
{
	int result=0;
	
	if(checkInterStudent(homeProvince)==1)		//Correct for 'IN'
		{
		result=1;
		}
	else if(checkInterStudent(homeProvince)==2)	//Only 'IN'
		{
		result=2;
		}
	else if(checkthaiStudent(homeProvince)==0)	//Nethier 'TH' nor 'IN'
		{
		result=3;
		}
	else if(checkDelimiter(homeProvince)==0)	//check delimiter '-'
		{
		result=4;
		}
	else if(strlen(homeProvince)>5)				//maximum length of home province is 5 ,TH-nn,TH-S,IN
		{
		result=5;
		}
	else if(checkS(homeProvince)==1)			//Valid
		{
		result=1;
		}
	else if(checkS(homeProvince)==2)			//check TH-S but they plug more than TH-S.....
		{
		result=6;
		}
	else if(checkS(homeProvince)==3)			//check TH-..... whether user type alphabet after dash or not 
		{
		result=7;
		}
	else if(checkNumberCode(homeProvince)==0)	//Check TH-..... whether number is not valid or not
		{
		result=7;
		}
	else
		{
		result=1;
		}
	return result;		
}

/*
This function check whether home province is IN.
If it is , it will send back value 1.
If it is but there are some number back IN,it will send back value 2.
If it is not IN,it will send back value 0
*/
int checkInterStudent(char homeProvince[])
{
	int test=0;
	int length=strlen(homeProvince);
	
	if((homeProvince[0]=='I')&&(homeProvince[1]=='N'))
		{
		test=1;
		
		if(length!=2)
			{
			test=2;
			}
		}
	return test;
}

/*
This program check whether home province is TH.
If it is,it will send back value 1.
If it is not,it will send back value 0
*/
int checkthaiStudent(char homeProvince[])
{
	int test=0;
	
	if((homeProvince[0]=='T')&&(homeProvince[1]=='H'))
		{
		test=1;
		}
	return test;
}

/*
This program check whether delimeter is - or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkDelimiter(char homeProvince[])
{
	int test=0;
	
	if(homeProvince[2]=='-')
		{
		test=1;
		}
	return test;
}

/*
This program check whether home province TH- it comes with
S or not.
If it is,it will send back value 1.
If it is TH-S but have something back, it will send back value 2.
If it is TH- and have any alphabet execpt S,it will send back value 3.
*/
int checkS(char homeProvince[])
{
	int test=0;
	int start;
	int length=strlen(homeProvince);
	
	if(homeProvince[3]=='S')
		{
		test=1;
		
		if(length>4)
			{
			test=2;
			}
		}
	else
		{
		for(start=3;start<length;start++)
			{
			if(isalpha(homeProvince[start]))
				{
				test=3;
				break;
				}
			}
		}
	return test;
}

/*
This function check whether home province TH-
and it comes with number 2 digits that match
with international rule or not.
If it is, it will send back value 1.
If it is not,it will send back value 0.
*/
int checkNumberCode(char homeProvince[])
{
	int number=0;
	int test=1;
		
	sscanf(homeProvince,"TH-%d",&number);

	if((number<10)||(number>96))
		{
		test=0;
		}
	else if((number>27)&&(number<30))
		{
		test=0;		
		}
	else if(number==59)
		{
		test=0;		
		}
	else if((number>67)&&(number<70))
		{
		test=0;
		}
	else if((number>77)&&(number<80))
		{
		test=0;
		}
	else if((number>86)&&(number<90))
		{
		test=0;
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorHomeProvince(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknown error\n");
			break;
		case 2:
			printf("\t\tInvalid - International student home province must be only 'IN'\n");
			break;
		case 3:
			printf("\t\tInvalid - Home province must start with either 'TH' or 'IN'\n");
			break;
		case 4:
			printf("\t\tInvalid - Delimiter must be -\n");
			break;
		case 5:
			printf("\t\tInvalid - Length of home province must not be more than 5 characters in form of TH-nn where n is a number\n");
			break;
		case 6:
			printf("\t\tInvalid - Special administrative city ends with only 1 'S'\n");
			break;
		case 7:
			printf("\t\tInvalid - Home province code is end with 'S'\n");
			printf("\t\t        - In number is from 10 to 27\n");
			printf("\t\t        - In number is from 30 to 58\n");
			printf("\t\t        - In number is from 60 to 67\n");
			printf("\t\t        - In number is from 70 to 77\n");
			printf("\t\t        - In number is from 80 to 86\n");
			printf("\t\t        - In number is from 90 to 96\n");
			break;
		}
}









/*
This function validate student GPA.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateGPA(char GPA[])
{
	int result=0;
	
	if(checkNotNumber(GPA)==0)								//check whether GPA has a 'not' number in every digits except digit 2
		{
		result=2;
		}
	else if(checkDecimalPoint(GPA)==0)						//check whether decimal point is . or not
		{
		result=3;
		}
	else if(checkRangeGPA(GPA)==0)							//check whether GPA is less than 0.00 or more than 4.00
		{
		result=4;
		}
	else
		{
		result=1;
		}
	return result;
}

/*
This function check whether GPA has alphabet or not.
If it has, it will send back value 0.
If it does not have,it will send back value 1.
*/
int checkNotNumber(char GPA[])
{
	int test=1;
	int length=strlen(GPA);
	int start;
	
	if(isdigit(GPA[0])==0)
		{
		test=0;
		}
	
	for(start=2;start<length;start++)
		{
		if(isdigit(GPA[start])==0)
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function check whether string has decimal point in string[1]
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkDecimalPoint(char GPA[])
{
	int test=1;
	int length=strlen(GPA);
	int start;
	
	if(strlen(GPA)>1)
		{
		if(GPA[1]!='.')
			{
			test=0;
			}
		}
	return test;
}

/*
This function check whether GPA is between 0.00-4.00 or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkRangeGPA(char GPA[])
{
	int test=1;
	float number=0;
	
	sscanf(GPA,"%f",&number);
	
	if((number<0)||(number>4))
		{
		test=0;
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorGPA(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknoun Error\n");
			break;
		case 2:
			printf("\t\tInvalid - GPA must be only number and decimal point\n");
			break;
		case 3:
			printf("\t\tInvalid - Decimal point must be .\n");
			break;
		case 4:
			printf("\t\tInvalid - GPA is between 0.00 to 4.00\n");
			break;
		}
}









/*
This function validate student gender.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateGender(char gender[])
{
	int result=0;
	
	if(checkGenderAlphabet(gender)==0)			//check whether gender is not alphabet
		{
		result=2;
		}
	else if(checkGender(gender)==0)				//check whether gender is only male,female, or oblivious
		{
		result=3;
		}
	else
		{
		result=1;
		}
	return result;
}

/*
This function check whether gender has only alphabet or not
If it is,it will send back value 1.
If it is not,it will send back value 0. 
*/
int checkGenderAlphabet(char gender[])
{
	int length=strlen(gender);
	int test=1;
	int start;
	
	for(start=0;start<length;start++)
		{
		if(isalpha(gender[start])==0)
			{
			test=0;
			break;
			}
		}
	return test;
}

/*
This function check whether gender is only
male,femake,or oblivious or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkGender(char gender[])
{
	int test=0;
	char listGender[3][32]={"Male","Female","Oblivious"};
	int start;
	
	for(start=0;start<3;start++)
		{
		if(strcasecmp(gender,listGender[start])==0)
			{
			test=1;
			}
		}
	return test;
}

/*
This function receive result and display error message
that depends on result number
*/
void printErrorGender(int result)
{
	switch(result)
		{
		case 0:
			printf("\t\tInvalid - Unknown Error\n");
			break;
		case 2:
			printf("\t\tInvalid - Gender must be in alphabet\n");
			break;
		case 3:
			printf("\t\tInvalid - There are 3 genders in this program\n");
			printf("\t\t          1. Male\n");
			printf("\t\t          2. Female\n");
			printf("\t\t          3. Oblivious\n");
			break;
		}
}
