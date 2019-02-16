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
		len = strlen(s)+1;
		name = new char[len ];
		strcpy_s(name, len , s);
	}
	string1(string1 &s)
	{

		len = strlen(s.name)+1;
		name = new char[len ];
		strcpy_s(name, len , s.name);
	}
	void operator +(string1 b)
	{
		string1 c;
		c.len = len + b.len+1;
		c.name = new char[c.len];
		strcpy_s(c.name, c.len, name);
		strcat_s(c.name,c.len , b.name);
		cout << c.name;
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
			len = s.len + 1;;
			name = new char[len];
			strcpy_s(name,len, s.name);
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
	s.name = new char[25];
	cout << "enter name" << endl;
	cin >> s.name;
	s.len = strlen(s.name) + 1;
	return cin;
}
int main()
{
	string1 s1("maneesha"), s2("gaddam"), s3, s4, s5;
	s1 + s2;
	cout << "after overloading + operator" << endl;
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