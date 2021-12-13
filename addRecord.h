/*
*	This function ask all data from user then write them to
*	text file together
*/
void mainAdd();



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
void addID(char *pID);



/*
*	addName function is used to add student name with surname
*	It will ask user to insert name and check whether it is valid.
*	If it is not, it will ask over and over until it is valid
*	then print it in text file
*/
void addName(char *pTitle,char *pName,char *pSurname);



/*
*	addBirthday function is used to add student date of birth.
*	It will ask user to insert date of birth and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addBirthday(char *pBirthday);



/*
*	addHomeProvince function is used to add student home province.
*	It will ask user to insert home province and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addHomeProvince(char *pHomeProvince);



/*
*	addGPA function is used to add latest GPA.
*	It will ask user to insert GPA and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addGPA(char *pGPA);



/*
*	addGender function is used to add student gender.
*	It will ask user to insert gender and check whether
*	it is valid.If it is not, it will ask over and over until 
*	it is valid then print it in text file
*/
void addGender(char *pGender);
