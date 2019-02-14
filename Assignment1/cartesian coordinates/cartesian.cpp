#include<iostream>
#include<math.h>
using namespace std;
class points
{
	signed int x;
	signed int y;
public:
	points()
	{
		x = y = 0;
	}
	points(signed int a, signed int b)
	{
		x = a;
		y = b;
	}
	friend void distance(points&, points &);
};
void distance(points &a, points &b)
{
	double res;
	res = sqrt((pow((abs(a.x - b.x)), 2)) + (pow((abs(a.y - b.y)), 2)));
	cout << "distance is"<<res<<endl;
}
int main()
{
	points p1(0, 5),p2(5, -5);
	distance(p1, p2);
	return 0;
}