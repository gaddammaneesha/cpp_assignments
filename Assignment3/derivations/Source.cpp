#include<iostream>
using namespace std;
class A
{
public:
	int public_var;
protected:
	int protected_var;
private:
	int private_var;
public:
	A()
	{
		public_var = 10;
		protected_var = 20;
		private_var = 30;
	}
};
class B :public A
{
	//the base is inherited with access specifier public hence there are no promotions or degradations.
public:
	B()
	{
		cout << public_var<<endl;//can be accessed as it remains public in base class
		cout << protected_var<<endl;//can be accessed as protected variable are accessible in derived class
	//	cout << private_var;//not accessible
	}
};
class C :protected A
{
public:
	C()
	{
		cout << public_var<<endl;//accesible as public variables are promoted to protected
		cout << protected_var<<endl;//protected remain protected
		//cout << private_var;//private have no change and are not accessible
	}
};
class D :private A
{
public:
	D()
	{
		cout << public_var<<endl;//accesible as public variables are promoted to protected
		cout << protected_var<<endl;//protected remain protected
		//cout << private_var;//private have no change and are not accessible 
	}
};
int main()
{
	B b;
	C c;
	D d;
	getchar();
	return 0;

}