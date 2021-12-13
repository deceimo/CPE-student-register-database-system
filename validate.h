/*
This function validate student ID.If ID is valid
,then function will send back value 1.But if ID
is invalid, it will send back other value that
is up to what is invalid
*/
int validateID(char ID[]);



/*
This function checks whether ID is all the numbers or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkAllDigits(char stringToCheck[]);


/*
This function checks whether third to seventh digit are 07050 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkMiddleID(char stringToCheck[]);


/*
This function checks whether last two digits is not 00 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkLastID(char stringToCheck[]);


/*
This function checks whether first two digits is between 55 to 63 or not
If it is,it will send back value 1 to validateCPE_ID.
;Otherwise,it will send back value 0
*/
int checkFrontID(char stringToCheck[]);


/*
This function checks whether eighth and ninth is 34(International)
or 10(Regular) or not.If it is,it will send back value 1 to validateCPE_ID
;Otherwise,it will send back value 0
*/
int checkProgramID(char stringToCheck[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorID(int result);







/*
This function validate student name.If name is valid
,then function will send back value 1.But if name
is invalid, it will send back other value that
is up to what is invalid
*/
int validateName(char title[],char name[],char surname[]);



/*
This function check whether title is only
Mr. Mrs. Ms. Miss or not.If it is,it will send
back value 1;Otherwise,it will send value 0
*/
int checkTitle(char stringToCheck[]);


/*
This function check whether string length is between
2-30 or not.If it is, it will return value 1;Otherwise,
it will send back value 0
*/
int checkNameLength(char stringToCheck[]);


/*
This function check whether string has only alphabet
or not.If it is, it will return value 1;Otherwise,
it will send back value 0
*/
int checkAlphabet(char stringToCheck[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorName(int result);


/*
This function receive string to modify by
changing first letter to be uppercase, and
other letter to be lowercase. It has 2 arguments
First is the string to be modified
Second is the modified string
*/
void properName(char string[],char *newString);







/*
This function validate student date of birth.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateBirthday(char date[]);



/*
This function checks whether date that user type has alphabets or not
If there is any alphabet in date,it will send value 0 back to validate Date
function;Otherwise,it will send value 1
*/
int checkAllNumber(char stringToCheck[]);


/*
This function checks correstness of day,month,and year
If there is nothing wrong,it will send value 8 back to 
validate date function;Otherwise,it will send 
values 1 to 8 by its invalidation
*/
int checkDateMonthYear(char stringToCheck[]);


/*
This function checks month of the user whether
it is a month that has only 30 days or not.
If it is,it will send value 1 back to validate date function
;Otherwise,it will send value 0
*/
int checkMonthMax30Day(int monthToCheck);


/*
This function checks whether date is in the future or not.
If it is,it will send back value 0.But if it is not,it will
send back value 1
*/
int checkFuture(char stringToCheck[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorBirthday(int result);







/*
This function validate student home province.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateHomeProvince(char homeProvince[]);



/*
This function check whether home province is IN.
If it is , it will send back value 1.
If it is but there are some number back IN,it will send back value 2.
If it is not IN,it will send back value 0
*/
int checkInterStudent(char homeProvince[]);


/*
This program check whether home province is TH.
If it is,it will send back value 1.
If it is not,it will send back value 0
*/
int checkthaiStudent(char homeProvince[]);


/*
This program check whether delimeter is - or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkDelimiter(char homeProvince[]);


/*
This program check whether home province TH- it comes with
S or not.
If it is,it will send back value 1.
If it is TH-S but have something back, it will send back value 2.
If it is TH- and have any alphabet execpt S,it will send back value 3.
*/
int checkS(char homeProvince[]);


/*
This function check whether home province TH-
and it comes with number 2 digits that match
with international rule or not.
If it is, it will send back value 1.
If it is not,it will send back value 0.
*/
int checkNumberCode(char homeProvince[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorHomeProvince(int result);







/*
This function validate student GPA.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateGPA(char GPA[]);



/*
This function check whether GPA has alphabet or not.
If it has, it will send back value 0.
If it does not have,it will send back value 1.
*/
int checkNotNumber(char GPA[]);


/*
This function check whether string has decimal point in string[1]
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkDecimalPoint(char GPA[]);


/*
This function check whether GPA is between 0.00-4.00 or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkRangeGPA(char GPA[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorGPA(int result);







/*
This function validate student gender.If it is valid
,then function will send back value 1.But if it
is invalid, it will send back other value that
is up to what is invalid
*/
int validateGender(char gender[]);



/*
This function check whether gender has only alphabet or not
If it is,it will send back value 1.
If it is not,it will send back value 0. 
*/
int checkGenderAlphabet(char gender[]);


/*
This function check whether gender is only
male,femake,or oblivious or not.
If it is,it will send back value 1.
If it is not,it will send back value 0.
*/
int checkGender(char gender[]);


/*
This function receive result and display error message
that depends on result number
*/
void printErrorGender(int result);
