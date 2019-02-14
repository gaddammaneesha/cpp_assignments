#include<iostream>
using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = img = 0;
	}
	complex(float a)
	{
		real = img = a;
	}
	complex(float a, float b)
	{
		real = a;
		img = b;
	}
	friend complex add(complex&, complex &);
	friend complex mul(complex &, complex &);
	void display()
	{
		cout << "real value is  " << real << endl;
		cout << "imaginary value is   " << img << endl;
	}
	~complex()
	{
		cout << "destructor invoked " << endl;
	}
};
complex  add(complex &a, complex &b)
{
	return complex(a.real + b.real, a.img + b.img);
}
complex  mul(complex &a, complex &b)
{
	return complex(a.real *b.real, a.img * b.img);
}
int main()
{
	complex c1(8.0), c2(5.3,7.6), c3;
	c3 = add(c1, c2);
	cout << "addition of 2 xcomplex numbers is  "<<endl;
	c3.display();
	c3 = mul(c1, c2);
	cout << endl<<"multiplication of 2 xcomplex numbers is  ";
	c3.display();
	return 0;
}