#include<iostream>
using namespace std;
class time
{
	int hours, min, sec;
public:
	time()
	{
		hours = min = sec = 0;
	}
	time(int a, int b, int c)
	{
		hours = a;
		min = b;
		sec = c;
	}
	void display()
	{
		cout << hours << ":" << min << ":" << sec << endl;
	}
	time add(time b)
	{
		time c;
		c.sec = sec + b.sec;
		c.min = min + b.min + (c.sec / 60);
		c.hours = hours + b.hours + (c.min / 60);
		c.min = c.min % 60;
		c.sec = c.sec % 60;
		return c;
	}
};
int main()
{
	time t1(5, 41, 30), t2(4, 20, 25), t3;
	t3 = t1.add(t2);
	t3.display();
	return 0;
}