#include<iostream>
#include <cstring>

using namespace std;

template<class T>

int linearSearch(T ar[], int len = 0, T key = 0) {
	for (int i = 0; i < len; i++) {
		if (ar[i] == key)
			return i;
	}
	return -1;
}

int linearSearch(char* ar[], int len, char* key) {
	for (int i = 0; i < len; i++) {
		if (strcmp(ar[i], key) == 0)
			return i;
	}
	return -1;
}

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
	bool operator==(const Complex &c) {
		return (this->real == c.real && this->img == c.img);
	}
	friend istream& operator >> (istream& cin, Complex &b);
	~Complex() {}
};

istream& operator >> (istream& in, Complex &x) {
	cout << "Real Img: ";
	in >> x.real >> x.img;
	return in;
}

int main() {
	int int_ar[] = { 21,9,8,10,22,2 };
	cout << "Int value found at: " << linearSearch(int_ar, 6, 22) << endl;;
	float flt_ar[] = { 22.0f, 9.0f, 8.0f, 10.0f, 21.0f, 2.0f };
	cout << "Float value found at: " << linearSearch(flt_ar, 6, 21.0f) << endl;
	double dbl_ar[] = { 22.1, 9.1, 8.3, 10.2, 21.1, 2.1 };
	cout << "Double value found at: " << linearSearch(dbl_ar, 6, 21.0) << endl;
	char* str_ar[] = { "Joey Tribbiane", "Chandler Bing", "Phoebe Buffay", "Rachel Green", "Monica Geller", "Ross Geller" };
	cout << "String  value found at: " << linearSearch(str_ar, 6, "Gunther") << endl;
	Complex complex_ar[6], c(2, 3);
	for (int i = 0; i < 6; i++)
		cin >> complex_ar[i];
	cout << "Complex obj found at: " << linearSearch(complex_ar, 6, c) << endl;
	getchar();
	return 0;
}