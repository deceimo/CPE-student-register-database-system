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
*	Third is the number of the students in text file
*/
void modifyMenu(int list[],int found,int line);



/*
*	modifyID function is used to modify ID by
*	asking user to type new ID then check whether
*	ID is valid or not.If it is, then it will change
*	data in the structure variable then write all data
*	in text file.There are 3 arguments.
*	First is list of student that is matched.
*	Second is a number of the student user want to modify
*	Third is the number of the students is text file
*/
void modifyID(int list[],int choice,int line);



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
void modifyName(int list[],int choice,int line);



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
void modifyBirthday(int list[],int choice,int line);



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
void modifyHomeProvince(int list[],int choice,int line);



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
void modifyGPA(int list[],int choice,int line);



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
void modifyGender(int list[],int choice,int line);
