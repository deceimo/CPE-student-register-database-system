/*
This structure is for 1 CPE student that contains
	1. Student ID
	2. Student title
	3. Student name
	4. Student surname
	5. Stiudent date of birth
	6. Student home province
	7. Student latest GPA
	8. Student gender
*/
typedef struct
	{
	char ID[32];			//Student ID			ex:63070503415
	char title[16];			//Student title			ex:Mr. Mrs.
	char name[32];			//Student name
	char surname[32];		//Student surname
	char birthday[32];		//Student date of birth	ex:18/07/2545
	char homeProvince[8];	//Student home province	ex:TH-10
	float GPA;				//Student latest GPA	ex:4.00
	char gender;			//Student gender		ex:M F O
	}DATA_T;
