
/*

	S641: Introduction to Programming			Spring 2019-2020
						Dr/ Saleh Mosbah
	date: 9/7/2020		Student name: Abdallah Aboudeif

*/

// stdio library for printf and scanf functions
#include <stdio.h>


// the main function return integar value
int main()
{
	/* Declreation of vurables
	Reg_num = registration number
	A = Number of students get 90 or more
	B = Number of students get 80 to less than 90
	C = Number of students get 70 to less than 80
	D = Number of students get 60 to less than 70
	F = Number of students get less than 60
	Test_dg = Total degrees for each student*
	Total_dg = Total degrees for all students*
	Grade1 = Mid-Term exam degree*
	Grade2 = Lab Quiz degree*
	Grade3 = Final Exam exam degree*
	*( Student can get a degree of (20) or (20.7) so that degree should be accepted as float number )
	Total_st = counter for students number
	SC_rate = The percent success rate
	Av = The average overall grade
    Ext = Exit program or start again
	*/
	int Reg_num,A,B,C,D,F,Total_st,Ext;
	float Sc_rate,Av,Total_dg,Grade1,Grade2,Grade3,Test_dg;

	// The main function loop to repeat whole the program code in case of restart
	while(1)
	{


	// Reset variables value
	A=B=C=D=F=Test_dg=Total_st=Sc_rate=Av=Total_dg=0;
    Grade1=Grade2=Grade3=-1.5;
	// Loop for entering grades
	do
	{
	// New screen for student data
	system("cls");
	printf("********** Welcome to Grading System ********** \n\n");
	// The next line is for testing program statements validation while developing program code, this is not a required part of the program
	//printf("Students=%d A=%d B=%d C=%d D=%d F=%d Total Grade=%.0f \n",Total_st,A,B,C,D,F,Total_dg);
	// Student registration number input
	printf("[Student %d]Enter student registration number or [-1] to finish: ",Total_st+1);
	scanf("%d",&Reg_num);
	// Registration number -1 means go to report
	if((int)Reg_num==-1){Reg_num=0;break;}
	// Degree of mid-term (repeat if value is unacceptable)
	do{
    // Wrong message 1f there is unacceptable entry value
    if (Grade1!=-1.5) printf("\n [Wrong Entry] %.1f is unacceptable value - Tray again: \n",Grade1);
	printf("\n [Mid-term Exam] > Enter student degree [0 to 30]: ");
	scanf("%f",&Grade1);
	// Absent student flag is -1
	if (Grade1==-1)Grade1=0;
	}while(Grade1>30 || Grade1<0);
	// Adding the given degree to total overall degree
	Total_dg+=Grade1;
	// Degree of Lab Quiz (repeat if value is unacceptable)
	do{
    // Wrong message 1f there is unacceptable entry value
    if (Grade2!=-1.5) printf("\n [Wrong Entry] %.1f is unacceptable value - Tray again: \n",Grade2);
	printf("\n [Lab Quiz] > Enter student degree [0 to 20]: ");
	scanf("%f",&Grade2);
	// Absent student flag is -1
	if (Grade2==-1)Grade2=0;
	}while(Grade2>20 || Grade2<0);
	// Adding the given degree to total overall grade
	Total_dg+=Grade2;
	// Degree of Final Exam (repeat if value is unacceptable)
	do{
    // Wrong message 1f there is unacceptable entry value
    if (Grade3!=-1.5) printf("\n [Wrong Entry] %.1f is unacceptable value - Tray again: \n",Grade3);
	printf("\n [Final Exam] > Enter student degree [0 to 50]: ");
	scanf("%f",&Grade3);
	// Absent student flag is -1
	if (Grade3==-1)Grade3=0;
	}while(Grade3>50 || Grade3<0);
	// Adding the given degree to total overall grade
	Total_dg+=Grade3;
	// Test if Final Exam grade is less than 15
	if (Grade3> 15) {
	// Grading student
	Test_dg=Grade1+Grade2+Grade3;
	if (Test_dg>=90)A++;
	else if (Test_dg>=80)B++;
	else if (Test_dg>=70)C++;
	else if (Test_dg>=60)D++;
	else if (Test_dg<60)F++;
	} else (F++);
	// Counting students number
	Total_st++;
	// Reset degrees virables
	Grade1=Grade2=Grade3=-1.5;
	}/* Infinite loop until student reg number = -1*/while(1);
	// If there are no students then don't divide by zero
	if(Total_st!=0){
	// Calculate the percent success rate
	Sc_rate=((float)Total_st-F)/(float)Total_st*100.0;
	// Calculate the average overall grade
	Av=Total_dg/(float)Total_st;
	}else {
	Sc_rate=0.0 ; Av=0.0 ;}
	// New screen for the output report
	system("cls");
	printf("********** Grading System report ********** \n");
	// grading system report
	printf("\nThe percent success rate = %.2f%% \nThe average overall grade = %.2f \nStudents number with grade A = %d \nStudents number with grade B = %d \nStudents number with grade C = %d \nStudents number with grade D = %d \nStudents number with grade F = %d \n",Sc_rate,Av,A,B,C,D,F);
	// Exit or restart input/output
	printf("\n[-1] to exit \n[1] to start program again \nExit or Start again ? ");
	scanf("%d",&Ext);
	// Exit or start again test
	if (Ext==1)continue;
	else if (Ext==-1)return(0);

	}

}
