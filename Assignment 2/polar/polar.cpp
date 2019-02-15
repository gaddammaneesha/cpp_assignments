#include <iostream>
using namespace std;
class polar
{
	int angle;
	int radius;
public:
	static int i;
	polar()
	{
		i++;
		cout << "object ivoked is" << i << endl;
	}
	~polar()
	{
		i--;
		cout << "object destroyed is" << i << endl;
	}
};
int polar::i = 0;
int main()
{
	polar p1, p2, p3, p4;
	cout << "total number of objects is " << polar::i << endl;
	return 0;
}

