#include <iostream>
using namespace std;
class employee
{
	int id;
	char name[30];
public:
	employee()
	{
		cout << "constructor invoked" << endl;
	}
	employee(const employee &a)
	{
		cout << "copy costructor invoked" << endl;
	}
	~employee()
	{
		cout << "destructor invoked" << endl;
	}
};
int main()
{
	employee x, y(x);
	cout << "size of object x  is " << sizeof(x) << endl;
	cout << "size of object y is " << sizeof(y) << endl;
	return 0;
}

