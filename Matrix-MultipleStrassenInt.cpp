//*****************strassen ************************************
#include<iostream>
#include<conio.h>
#include <random>
using namespace std;

void create(int);
int**subsum(int, int **, int**, char);
int **cal(int, int **, int**);

random_device rd;
mt19937 mt(rd());
//uniform_real_distribution<double> dist(-10, 10);	//Use uniform distribution random variable
normal_distribution<double> dist(5.0, 2.0);

void main()
{
	int n = 4; //Set the number of row and column

	while (n % 2 != 0)
	{
		cout << "Size of matrices must be even" << endl;
		cout << "please enter  size matrices :";
		cin >> n;
	}
	create(n);
}
//***************create**********
void create(int n)
{
	int i, j;
	int **s, **v, **c;
	cout << "please enter first matrice:" << endl;
	s = new int*[n];
	for (i = 0; i<n; i++)
		s[i] = new int[n];
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		s[i][j]=(int)dist(mt);
	for (i = 0; i<n; i++)
	{
		cout << endl;
		for (j = 0; j<n; j++)
			cout << s[i][j] << "     ";
	}

	cout << endl << "please enter matrice two :" << endl;
	v = new int*[n];
	for (i = 0; i<n; i++)
		v[i] = new int[n];
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		v[i][j]=(int)dist(mt);

	for (i = 0; i<n; i++)
	{
		cout << endl;
		for (j = 0; j<n; j++)
			cout << v[i][j] << "     ";
	}

	c = new int*[n];
	for (i = 0; i<n; i++)
		c[i] = new int[n];
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		c[i][j] = 0;

	c = cal(n, s, v);
	for (i = 0; i<n; i++) 
	{
		cout << endl;
		for (j = 0; j<n; j++)
			cout << c[i][j] << "     ";
	}
}
//**********************cal*******************
int** cal(int n, int **s, int**v)
{
	int i, j, k, **c, t, **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22;
	int **m1, **m2, **m3, **m4, **m5, **m6, **m7, **w, **p1, **p2;
	c = new int*[n];
	for (i = 0; i<n; i++)
		c[i] = new int[n];


	if (n <= 2){
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++) {
			c[i][j] = 0;
			for (k = 0; k<n; k++)
				c[i][j] += s[i][k] * v[k][j];
		}
		return c;
	}
	else {
		t = n / 2;
		//*****************************a and b****************
		a11 = new int*[t];
		for (i = 0; i<t; i++)
			a11[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a11[i][j] = s[i][j];

		a12 = new int*[t];
		for (i = 0; i<t; i++)
			a12[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a12[i][j] = s[i][j + t];

		a21 = new int*[t];
		for (i = 0; i<t; i++)
			a21[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a21[i][j] = s[i + t][j];

		a22 = new int*[t];
		for (i = 0; i<t; i++)
			a22[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a22[i][j] = s[t + i][j + t];
		//*************************************************

		b11 = new int*[t];
		for (i = 0; i<t; i++)
			b11[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b11[i][j] = v[i][j];

		b12 = new int*[t];
		for (i = 0; i<t; i++)
			b12[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b12[i][j] = v[i][j + t];

		b21 = new int*[t];
		for (i = 0; i<t; i++)
			b21[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b21[i][j] = v[i + t][j];

		b22 = new int*[t];
		for (i = 0; i<t; i++)
			b22[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b22[i][j] = v[t + i][j + t];


		//*****************************m1-m7************************


		m1 = new int*[t];
		for (i = 0; i<t; i++)
			m1[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m1[i][j] = 0;

		m2 = new int*[t];
		for (i = 0; i<t; i++)
			m2[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m2[i][j] = 0;

		m3 = new int*[t];
		for (i = 0; i<t; i++)
			m3[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m3[i][j] = 0;

		m4 = new int*[t];
		for (i = 0; i<t; i++)
			m4[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m4[i][j] = 0;

		m5 = new int*[t];
		for (i = 0; i<t; i++)
			m5[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m5[i][j] = 0;

		m6 = new int*[t];
		for (i = 0; i<t; i++)
			m6[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m6[i][j] = 0;

		m7 = new int*[t];
		for (i = 0; i<t; i++)
			m7[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m7[i][j] = 0;


		p1 = new int*[t];
		for (i = 0; i<t; i++)
			p1[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			p1[i][j] = 0;

		p1 = new int*[t];
		for (i = 0; i<t; i++)
			p1[i] = new int[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			p1[i][j] = 0;
		//**********************calculate m1-m7**********

		p1 = subsum(t, a11, a22, 'd');
		p2 = subsum(t, b11, b22, 'd');
		m1 = cal(t, p1, p2);

		p1 = subsum(t, a21, a22, 'd');
		m2 = cal(t, p1, b11);

		p1 = subsum(t, b12, b22, 'k');
		m3 = cal(t, a11, p1);

		p1 = subsum(t, b21, b11, 'k');
		m4 = cal(t, a22, p1);

		p1 = subsum(t, a11, a12, 'd');
		m5 = cal(t, p1, b22);

		p1 = subsum(t, a21, a11, 'k');
		p2 = subsum(t, b11, b12, 'd');
		m6 = cal(t, p1, p2);

		p1 = subsum(t, a12, a22, 'k');
		p2 = subsum(t, b21, b22, 'd');
		m7 = cal(t, p1, p2);


		w = new int*[n];
		for (i = 0; i<n; i++)
			w[i] = new int[n];
		p1 = subsum(t, m1, m4, 'd');
		p2 = subsum(t, p1, m5, 'k');
		p2 = subsum(t, p2, m7, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++){
			w[i][j] = p2[i][j];
		}

		p1 = subsum(t, m3, m5, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++){
			w[i][j + t] = p1[i][j];
		}

		p1 = subsum(t, m2, m4, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			w[i + t][j] = p1[i][j];

		p1 = subsum(t, m1, m3, 'd');
		p2 = subsum(t, p1, m2, 'k');
		p2 = subsum(t, p2, m6, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			w[i + t][j + t] = p2[i][j];

		return w;

	}

}
//*********************sub and sum***************
int**subsum(int n, int **s, int **v, char ch)
{

	int **m, i, j;
	m = new int*[n];
	for (i = 0; i<n; i++)
		m[i] = new int[n];
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		m[i][j] = 0;
	if (ch == 'd'){
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			m[i][j] = s[i][j] + v[i][j];
	}
	else{
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			m[i][j] = s[i][j] - v[i][j];
	}
	return m;

}
