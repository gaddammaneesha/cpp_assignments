#include<iostream>
using namespace std;
class distance2;
class distance1
{
	double m;
	double cm;
public:
	distance1()
	{
		cout << "constructor for distance1 invoked"<<endl;
	}
	distance1(double a, double b)
	{
		m = a;
		cm = b;
	}
	friend distance1 add(distance1 &, distance2 &);
	void display()
	{
		cout << "distance in metres is" << m << endl;
		cout << "distance in centimetres is" << cm << endl;
	}
};
class distance2
{
	double feet;
	double inch;
public:
	distance2()
	{
		cout << "constructor for distance2 invoked" << endl;
	}
	distance2(double a, double b)
	{
		feet = a;
		inch= b;
	}
	friend distance1 add(distance1 &, distance2 &);
};
distance1 add(distance1 &a, distance2 &b)
{
	distance1 temp;
	b.feet = 0.348*b.feet;//converting to metres
	b.inch = 2.54*b.inch;//converting to centimetres
	temp.m = a.m + b.feet;
	temp.cm = a.cm + b.inch;
	return temp;
}
int main()
{
	distance1 x(5.2, 3.3), y;
	distance2 z(7.3, 4.1);
	y = add(x,z);
	y.display();
	int a;
	cin >> a;
	return 0;
}