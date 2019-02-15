# include<iostream>
using namespace std;
class matrix2;
class matrix1
{
	int **a,m,n;
public:
	matrix1()
	{
		a = NULL;
		m = n = 0;
	}
	void get_input()
	{
		cout << "enter rows and columns " << endl;
		cin >> m >> n;
		int i, j;
		a = new int*[m];
		for (i = 0; i < m; i++)
			a[i] = new int[n];
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				cin >> a[i][j];
		}
	}
	friend void mul(matrix1 &, matrix2 &);
};
class matrix2
{
	int **b, p, q;
public:
	void get_input()
	{
		cout << "enter rows and columns " << endl;
		cin >> p >> q;
		int i,j;
		b = new int*[p];
		for (i = 0; i < p; i++)
			b[i] = new int[q];
		cout << "enter elements" << endl;
		for (i = 0; i < p; i++)
		{
			for (j = 0; j < q; j++)
				cin >> b[i][j];
		}
	}
	friend void mul(matrix1 &, matrix2 &);
};
void  mul(matrix1 &x, matrix2 &y)
{
	matrix1 c;
	int i, j, sum, k = 0;
	if (x.n != y.p)
	{
		cout << "matrix multiplication not possible";
	}
	else
	{
		c.a = new int*[x.m];
		for (i = 0; i < x.m; i++)
			c.a[i] = new int[y.q];
		c.m = x.m;
		c.n = y.q;
		cout << c.m << c.n;
		for (i = 0; i < c.m; i++)
		{
			sum = 0;
			for (j = 0; j < y.q; j++)
			{
				for (k = 0; k < y.p; k++)
					sum = sum + ((x.a[i][k]) * (y.b[k][j]));
				c.a[i][j] = sum;
			}
		}
	}
	cout << "after matrix multiplication the result is:" << endl;
	for (i = 0; i < c.m; i++)
	{
		for (j = 0; j <k; j++)
			cout << c.a[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	matrix1 p;
	matrix2 q;
	p.get_input();
	q.get_input();
	mul(p, q);
	system("pause");
}