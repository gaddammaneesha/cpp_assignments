#include<iostream>
#include<math.h>
using  namespace std;
class number
{
	int n;
public:
	number()
	{
		cout << "default constructor invoked " << endl;
		n = 0;
	}
	number(int a)
	{
		cout << "parameterized constructor invoked" << endl;
		n = a;
	}
	number(number &a)
	{
		cout << "copy constructor invoked" << endl;
		n = a.n;
	}
	~number()
	{
		cout << "destructor invoked" << endl;
	}
	void display()
	{
		cout << n << endl;
	}
	number operator +(number b)
	{
		return (number(n + b.n));
	}
	number operator -(number b)
	{
		return (number(abs(n - b.n)));
	}
	number operator ,(number a)
	{
		return (number(n));
	}
	number* operator ->()
	{
		return (this);
	}
	
	friend number operator -(number );
	friend number operator ++(number);
	friend number operator ++(number &,int );
	friend ostream& operator << (ostream &cout,number);
	friend istream& operator >> (istream &cin, number &s);
};
ostream& operator <<(ostream &cout, number a)
{
	cout << "n values is" << a.n << endl;
	return cout;
}
istream & operator >> (istream &cin, number &s)
{
	cout << "enter n value" << endl;
	cin >> s.n;
	return cin;
}
number operator -(number s)
{
	number c;
	c.n= -s.n;
	return c;
}
number operator ++(number s)
{
	number c;
	c.n = ++s.n;
	return c;
}
number operator ++(number &s,int x)
{
	number c;
	c.n = s.n++;
	return c;
}

int main()
{
	number n1(2), n2(n1), n3,n4,n5(6);
	n3 = n1 + n2;
	cout <<endl<< "binary addition value is:";
	n3.display();
	n3 = n1 - n2;
	cout <<endl<< "binary subtraction value is:";
	n3.display();
	n3 =-n1;
	cout << endl << "unary subtraction value is:";
	n3.display();
	n3 =++n1;
	cout << endl <<"after overaloading prefix ++ n3 value is:";
	n1.display();
	n3.display();
	n3 = n5++;
	cout << endl << "after overaloading postfix ++ n3 value is:";
	n5.display();
	n3.display();
	n3 = n5,n1;
	cout << endl << "overloading , opeartor n3 values is:";
	n3.display();
	cout << endl << "overloading -> opeartor n3 values is:";
	n3->display();
	cout << "overloading >> opertor" << endl;
	cin >> n4;
	cout << "overloading << opertor" << endl;
	cout <<n4;
	return 0;
}
