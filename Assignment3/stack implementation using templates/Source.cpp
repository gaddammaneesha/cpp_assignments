#include <iostream>
#include <cstring>

using namespace std;

class Complex {
	int real;
	int img;
public:
	Complex() {}
	Complex(int real, int img) {
		this->real = real;
		this->img = img;
	}
	Complex(const Complex &c) {
		this->real = c.real;
		this->img = c.img;
	}
	friend ostream& operator<<(ostream &, Complex);

	~Complex() {}
};

ostream& operator<<(ostream& out, Complex c) {
	if (c.img < 0)
		out << c.real << c.img << "i";
	else
		out << c.real << " + " << c.img << "i";
	return out;
}

template < class T >

class Stack {
protected:
	T stk[20];
	int top;
public:
	Stack() {
		top = -1;
	}
	void push(T item) 
	{
		try {
			if (top == 20) 
			{
				throw "Overflow\n";
			}
			stk[++top] = item;
			cout << "Pushed " << item << endl;
		}
		catch (char * s) {
			cout << s << endl;
		}
	}

	void push(char* str, int x)
	{
		try
		{
			if (top == 20)
				throw "Overflow";
			stk[++top] = new char[strlen(str) + 1];
			stk[top] = str;
			cout << "Pushed " << str << endl;
		}
		catch (char * s) {
			cout << s << endl;
		}
	}

	T pop() {
		if (top == -1) {
			cout << "Underflow" << endl;
		}
		else {
			cout << "Poped " << stk[top] << endl;;
			return (stk[top--]);

		}
	}

	char* pop(int x ) {
		if (top == -1)
			cout << "Underflow" << endl;
		else {
			cout << "Popped " << stk[top] << endl;
			return stk[top--];
		}
	}

	void display() {
		if (top == -1) {
			cout << "Underflow" << endl;
		}
		else {
			for (int i = top; i != -1; i--) {
				cout << stk[i] << ", ";
			}
		}
		cout << endl << endl;
	}
};


int main() {
	Stack <int> iStack;
	iStack.push(10);
	iStack.push(9);
	iStack.pop();
	iStack.push(2);
	cout << "Integer Stack Elements: ";
	iStack.display();

	Stack <float> floatStack;
	floatStack.push(21.2f);
	floatStack.push(9.7f);
	floatStack.push(39.8f);
	floatStack.pop();
	floatStack.pop();
	cout << "Float Stack Elements: ";
	floatStack.display();

	Stack<char*> stringStack;
	stringStack.push("Harry Potter", -1);
	stringStack.push("Hermione Granger", -1);
	stringStack.push("Ronald Weasley", -1);
	stringStack.pop(-1);
	cout << "String Stack Elements: ";
	stringStack.display();

	Stack<Complex> complexStack;
	Complex c1(2, 3), c2(3, 4), c3(4, 5), c4(89, 78);
	complexStack.push(c1);
	complexStack.pop();
	complexStack.push(c2);
	complexStack.push(c3);
	complexStack.push(c4);
	cout << "Complex Stack Elements: ";
	complexStack.display();
	getchar();
	return 0;
}