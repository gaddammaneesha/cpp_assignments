#include<iostream>
using namespace std;
class Shape
{
protected:
	int length;
	int breadth;
	int area;
public:
	Shape()
	{
		cout << "Base class Constructor\n";
	}
	Shape(int x, int y)
	{
		length = x;
		breadth = y;
	}
	Shape(int x)
	{
		length = x;
		breadth = x;
	}
	virtual int Area()
	{
		return length*breadth;
	}
};
class Rectangle :public Shape
{
public:
	Rectangle()
	{

	}
	Rectangle(int x, int y) :Shape(x, y)
	{

	}
	int Area()
	{
		return length*breadth;
	}
};
class Square :public Shape
{
public:
	Square()
	{

	}
	Square(int x) :Shape(x)
	{

	}
	int Area()
	{
		return length*breadth;
	}
};
class Triangle :public Shape
{
public:
	Triangle()
	{

	}
	Triangle(int x, int y) :Shape(x, y)
	{

	}
	int Area()
	{
		return 0.5*(length*breadth);
	}
};
int main()
{
	Shape *S;
	Rectangle r(5, 4);
	Triangle t(4, 5);
	Square s(4);
	S = &r;
	cout << S->Area() << endl;
	S = &t;
	cout << S->Area() << endl;
	S = &s;
	cout << S->Area();
	getchar();
	return 0;
}