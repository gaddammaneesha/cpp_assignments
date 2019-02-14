#include<iostream>
using namespace std;
class arithmetic
{
	int a;
	int b;
public:
	arithmetic(int m,int n)
	{
		a = m;
		b = n;
	}
	arithmetic()
	{
		cin >> a >> b;
	}
	inline void add();
	inline void sub();
	inline void mul();
	inline void div();
	~arithmetic()
	{
		cout << "destructor invoked " << endl;
	}
};
void arithmetic :: add()
{
	int c = a + b;
	cout << "addition result is " << c << endl;
}
void arithmetic::sub()
{
	int c = a - b;
	cout << "subtraction result is " << c << endl;
}
void arithmetic::mul()
{
	int c = a * b;
	cout << "multuiplication result is " << c << endl;
}
void arithmetic::div()
{
	int c = a / b;
	cout << "division result is " << c << endl;
}


int main()
{
	arithmetic a1(5, 7), a2;
	a1.add();
	a1.sub();
	a1.mul();
	a1.div();
	a2.add();
	a2.sub();
	a2.mul();
	a2.div();

	return 0;
}