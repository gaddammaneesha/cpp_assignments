#include <iostream>
using namespace std;
void swap_value(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_reference(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	int ch, a, b;
	cout << "enter a and b values" << endl;
	cin >> a >> b;
	while (1)
	{
		cout << "enter yout choice" << endl;
		cout << "1 swap by value " << "2 swap by reference " << endl;
		cin >> ch;
		cout << "values before swapping are:" << a << "\t" << b << endl;
		switch (ch)
		{
		case 1:swap_value(a, b);
			cout << "after swapping by value a,b values are" << a << " " << b << endl;
			break;
		case 2:swap_reference(&a, &b);
			cout << "after swapping by reference a,b values are" << a << " " << b << endl;
			break;
		}
	}
	return 0;
}

