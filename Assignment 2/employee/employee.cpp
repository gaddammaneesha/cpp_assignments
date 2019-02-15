#include<iostream>
using namespace std;
class employee
{
	int empno;
	char name[50];
	long int sal;
public:
	employee()
	{
		cout << "constructor invoked" << endl;
	}
	friend istream & operator >> (istream &cin, employee &);
	void display()
	{
		cout << "employee no:" << empno << endl;
		cout << "employee name:" <<name << endl;
		cout << "employee salary:" << sal << endl;
	}
};
istream & operator >> (istream &cin, employee &e)
{
	cout << "enter employee number:" << endl;
	cin >> e.empno;
	cout << "enter employee name:" << endl;
	cin >> e.name;
	cout << "enter employee salary:" << endl;
	cin >> e.sal;
	return cin;
}
int main()
{
	int i;
	employee e[5];
	for (i = 0; i < 5; i++)
		cin >> e[i];
	cout << "displaying employee details" << endl;
	for (i = 0; i < 5; i++)
		 e[i].display();
	return 0;
}
