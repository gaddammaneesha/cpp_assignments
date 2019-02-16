#include<iostream>
#include<string.h>
using namespace std;
class string1
{
	char *name;
	int len;
public:
	string1()
	{
		name = NULL;
		len = 0;
	}
	string1(char *s)
	{
		len = strlen(s);
		name = new char[len + 1];
		strcpy_s(name, len + 1, s);
	}
	string1(string1 &s)
	{

		len = strlen(s.name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, s.name);
	}
	string1 operator +(string1 b)
	{
		string1 c;
		c.len = len + b.len;
		c.name = new char[c.len + 1];
		strcpy_s(c.name, c.len + 1, name);
		strcat_s(c.name, c.len + 1, b.name);
		return c;
	}

	char& operator [](int n)
	{
		return name[n];
	}
	string1 operator =(string1 s)
	{
		if (name != NULL)
			delete[]name;
		else
		{
			s.len = strlen(name);
			s.name = new char[s.len + 1];
			strcpy_s(s.name, s.len + 1, name);
		}
		return (*this);
	}
	friend ostream& operator << (ostream &cout, string1);
	friend istream& operator >> (istream &cin, string1 &s);
};
ostream& operator <<(ostream &cout, string1 a)
{
	cout << " name  is" << a.name << endl;
	cout << "length is" << a.len << endl;
	return cout;
}
istream & operator >> (istream &cin, string1 &s)
{
	cout << "enter name" << endl;
	cin >> s.name;
	s.len = strlen(s.name) + 1;
	return cin;
}
int main()
{
	string1 s1("maneesha"), s2("gaddam"), s3, s4, s5;
	s3 = s1 + s2;
	cout << "after overloading + operator" << endl;
	cout << s3;
	s2[3] = 'i';
	cout << "after overloading [] operator is " << endl;
	cout << s2;
	s4 = s2;
	cout << "after overloading = operator is " << endl;
	cout << s4;
	cin >> s5;
	cout << s5;
	return 0;
}