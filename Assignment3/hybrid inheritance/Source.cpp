#include<iostream>
using namespace std;
class Person
{
protected:
	int age;
	char name[50];
public:
	Person() {}
	Person(int age, const char *s)
	{
		this->age = age;
		strcpy(name, s);
	}
	void GetDetails()
	{
		cout << "Age - " << age << endl;
		cout << "Name - " << name << endl;
	}
};
class physique :public virtual Person
{
protected:
	int height;
	int weight;
public:
	physique() {}
	physique(int h, int w)
	{
		height = h;
		weight = w;
	}
	void GetDetails()
	{
		cout << "Height - " << height << endl;
		cout << "Weight - " << weight << endl;
	}
};
class Family :public virtual Person
{
protected:
	int numChildren;
	char religion;
public:
	Family() {}
	Family(int num, char r)
	{
		numChildren = num;
		religion = r;
	}
	void GetDetails()
	{
		cout << "Number of Children - " << numChildren << endl;
		cout << "Religion - " << religion << endl;
	}
};
class Employee :public physique, Family
{
public:
	Employee(int num, char r, int height, int weight, int age, const char *s) :physique(height, weight), Family(num, r), Person(age, s)
	{

	}
	void GetDetails()
	{
		printf("Age - %d\nName - %s\nHeight - %d\nWeight - %d\nNum - %d\nReligion - %c", age, name, height, weight, numChildren, religion);
	}
};
int main()
{
	Employee e(5, 'V', 180, 60, 21, "manee");
	e.GetDetails();
}