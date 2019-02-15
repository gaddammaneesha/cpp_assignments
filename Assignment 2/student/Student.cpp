#include<iostream>
using namespace std;
class student
{
	int rollno,m1,m2,m3,total;
	char name[30],grade[15];
public:
	student()
	{
		total = 0;
	}
	friend void generate_results(student[], int n);
	friend ostream& operator << (ostream &cout, student s);
	friend istream& operator >> (istream &cin, student &s);
};
ostream& operator <<(ostream &cout, student s)
{
	cout << "rollno is" << s.rollno << endl;
	cout << "name  is" << s.name<< endl;
	cout << "total marks  is" << s.total << endl;
	cout << "grade  is " << s.grade << endl;
	return cout;
}
istream & operator >> (istream &cin, student &s)
{
	cout << "enter rollno" << endl;
	cin >> s.rollno;
	cout << "enter name" << endl;
	cin >> s.name;
	cout << "enter marks for 3 subjects" << endl;
	cin >> s.m1 >> s.m2 >>s. m3;
	return cin;
}
void generate_results(student s[], int n)
{
	int i;
	float avg;
	for (i = 0; i < n; i++)
	{
		s[i].total += s[i].m1 + s[i].m2 + s[i].m3;
		avg = (float)(s[i].total) / 3;
		if (avg > 80 && avg <= 100)
			strcpy_s(s[i].grade, 15,"first class");
		else if (avg > 60 && avg <= 80)
			strcpy_s(s[i].grade, 15,"second class");
		else if (avg >= 60 && avg <= 40)
			strcpy_s(s[i].grade,15, "third class");
		else
			strcpy_s(s[i].grade,15,"fail");
	}
}
int main()
{
	student s[3];
	int i;
	for (i = 0; i < 3; i++)
		cin >> s[i];
	generate_results(s, 3);
	for (i = 0; i < 3; i++)
		cout << s[i];
	return 0;
}