#include<iostream>
using namespace std;
class mystring
{
	char *name;
	int length;
public:
	mystring()	//default constructor
	{
		name = NULL;
		length = 0;
	}
	mystring(char *s, int len)	//parameterised constructor
	{
		length = len;
		name = new char[length + 1];
		strcpy(name, s);
	}
	mystring(const mystring &s)	//copy constructor
	{
		length = s.length;		//shallow copying
		name = new char[length + 1];
		strcpy(name, s.name);
	}
	void operator +(mystring s2)
	{
		//concatenation
		mystring temp;
		temp.length = (length+1) + (s2.length+1) + 1;
		temp.name = new char[temp.length];
		strcpy(temp.name, name);
		strcat(temp.name, s2.name);
		cout << "concatenated string is " << temp.name<<endl;
	}
	void operator =(mystring s)
	
	{
	length = s.length + 1;
	name = new char[length];
	strcpy(name, s.name);
	}
	void operator <(mystring s)
	{
		if (strcmp(name, s.name) == -1)	//1st string less than 2nd string
			cout << "true";
		else
			cout << "false";
	}
	friend ostream& operator <<(ostream &, mystring);
	friend istream& operator >>(istream &, mystring&);
	friend void sort(mystring[],int);
	~mystring()
	{
		delete[] name;	//deallocation
	}
};
ostream& operator <<(ostream& cout, mystring s)
{
	cout << "length of string is" << s.length<<endl;//displaying 
	cout << "name is" << s.name<<endl;
	return cout;
}
istream& operator >>(istream& cin, mystring&s)
{
	cout << "enter length"<<endl;	//reading input
	cin >> s.length;
	s.name = new char[s.length + 1];
	cout << "enter name"<<endl;
	cin >> s.name;
	return cin;
}
void sort(mystring s[], int n)
{
	int i, j,flag=0;
	for (i = 0; i < n; i++)		//logic for bubble sort
	{
		flag = 0;
		for (j = i + 1; j < n - i-1; j++)
		{
			if (strcmp(s[i].name, s[j].name) ==1)//1st sting greater than 2nd string
			{
				flag = 1;
				char temp[50];
				strcpy(temp, s[i].name);
				strcpy(s[i].name,s[j].name);
				strcpy(s[j].name, temp);
			}
		}
		if (flag == 0)
			break;
	}
	cout << "after sorting\n";
	for (i = 0; i < n; i++)
	{
		cout << s[i].name<<"\n";		//displaying sorted strings
	}
}

int main()
{
	mystring s1("maneesha", 8), s2("sai", 3), s3(s2), s4,s5[3];
	s1+s2;	//overloading + operator
	s4=s2;	//overloading = operator
	cout << "after copying\n";
	cout << s4;//overloading <<
	cout << "overloading < operator\n";
	s1 < s2;
	cout << "enter names for sorting\n";
	for(int i=0;i<3;i++)	//array of objects
	cin >> s5[i];
	sort(s5, 3);	//sorting
	system("pause");
	return 0;
}