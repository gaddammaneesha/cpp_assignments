#include<iostream>
#include<string.h>
using namespace std;
class Student
{
	char sname[30];
	int marks1, marks2, marks3;
	char grade[20];
public:
	void set_data(char *name, int m1, int m2, int m3)
	{

		strcpy_s(sname, sizeof(char) + 30, name);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
		int d = calculateAvg(m1, m2, m3);
		computegrade(d);
	}
	int calculateAvg(int m1, int m2, int m3)
	{
		return (m1 + m2 + m3) / 3;
	}
	void computegrade(int avg)
	{
		if (avg > 60)
			strcpy_s(grade, sizeof(char) + 15, "First class");
		else if (avg > 50 && avg < 60)
			strcpy_s(grade, sizeof(char) + 15, "Second class");
		else if (avg > 40 && avg < 50)
			strcpy_s(grade, sizeof(char) + 15, "Third class");
		else
			strcpy_s(grade, sizeof(char) + 15, "Fail");
	}
	void display()
	{
		cout << "Student details are:";
		cout << "\nName:" << sname;
		cout << "\nMarks1:" << marks1 << "\nMarks2:" << marks2 << "\nMarks3:" << marks3;
		cout << "\nGrade obtained is:" << grade;
	}
};
int main()
{
	Student s;
	s.set_data("maneesha", 60, 75, 86);
	s.display();
	return 0;
}