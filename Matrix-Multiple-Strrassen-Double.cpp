//*****************strassen ************************************
#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;
const int nn = 4;
unsigned int addNum = 0;
unsigned int mulNum = 0;

//*********************sub and sum***************
double**subsum(int n, double **s, double **v, char ch)
{

	double **m;
	int i, j;
	m = new double*[n];
	for (i = 0; i<n; i++)
		m[i] = new double[n];
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		m[i][j] = 0;
	if (ch == 'd')
	{
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			m[i][j] = s[i][j] + v[i][j];
	}
	else
	{
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			m[i][j] = s[i][j] - v[i][j];
	}
	return m;

	for (int i = 0; i < n; i++)
	{
		delete[] m[i];

	}
	delete[] m;
}
//**********************cal*******************
double** cal(int n, double **s, double**v)
{
	int i, j, k, t;
	double **c, **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22;
	double **m1, **m2, **m3, **m4, **m5, **m6, **m7, **w, **p1, **p2;
	c = new double*[n];
	for (i = 0; i<n; i++)
		c[i] = new double[n];


	if (n <= 2)
	{
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
		{
			c[i][j] = 0;
			for (k = 0; k<n; k++)
				c[i][j] += s[i][k] * v[k][j];
		}
		return c;
	}
	else
	{
		t = n / 2;
		//*****************************a and b****************
		a11 = new double*[t];
		for (i = 0; i<t; i++)
			a11[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a11[i][j] = s[i][j];

		a12 = new double*[t];
		for (i = 0; i<t; i++)
			a12[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a12[i][j] = s[i][j + t];

		a21 = new double*[t];
		for (i = 0; i<t; i++)
			a21[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a21[i][j] = s[i + t][j];

		a22 = new double*[t];
		for (i = 0; i<t; i++)
			a22[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			a22[i][j] = s[t + i][j + t];
		//*************************************************

		b11 = new double*[t];
		for (i = 0; i<t; i++)
			b11[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b11[i][j] = v[i][j];

		b12 = new double*[t];
		for (i = 0; i<t; i++)
			b12[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b12[i][j] = v[i][j + t];

		b21 = new double*[t];
		for (i = 0; i<t; i++)
			b21[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b21[i][j] = v[i + t][j];

		b22 = new double*[t];
		for (i = 0; i<t; i++)
			b22[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			b22[i][j] = v[t + i][j + t];


		//*****************************m1-m7************************


		m1 = new double*[t];
		for (i = 0; i<t; i++)
			m1[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m1[i][j] = 0;

		m2 = new double*[t];
		for (i = 0; i<t; i++)
			m2[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m2[i][j] = 0;

		m3 = new double*[t];
		for (i = 0; i<t; i++)
			m3[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m3[i][j] = 0;

		m4 = new double*[t];
		for (i = 0; i<t; i++)
			m4[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m4[i][j] = 0;

		m5 = new double*[t];
		for (i = 0; i<t; i++)
			m5[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m5[i][j] = 0;

		m6 = new double*[t];
		for (i = 0; i<t; i++)
			m6[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m6[i][j] = 0;

		m7 = new double*[t];
		for (i = 0; i<t; i++)
			m7[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			m7[i][j] = 0;


		p1 = new double*[t];
		for (i = 0; i<t; i++)
			p1[i] = new double[t];
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
			p1[i][j] = 0;

		p1 = new double*[t];
		for (i = 0; i<t; i++)
			p1[i] = new double[t];
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


		w = new double*[n];
		for (i = 0; i<n; i++)
			w[i] = new double[n];
		p1 = subsum(t, m1, m4, 'd');
		p2 = subsum(t, p1, m5, 'k');
		p2 = subsum(t, p2, m7, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
		{
			w[i][j] = p2[i][j];
		}

		p1 = subsum(t, m3, m5, 'd');
		for (i = 0; i<t; i++)
		for (j = 0; j<t; j++)
		{
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
//***************create**********
void create(int n, double **s, double **v, double **c)
{
	int i, j;

	c = cal(n, s, v);
	for (i = 0; i<n; i++) 
	{
		cout << endl;
		for (j = 0; j<n; j++)
			cout << c[i][j] << "     ";
	}
}
void main()
{
	double **x = new double*[nn];
	double **y = new double*[nn];
	double **z = new double*[nn];
	for (size_t i = 0; i < nn; i++)
	{
		x[i] = new double[nn];
		y[i] = new double[nn];
		z[i] = new double[nn];
	}
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(-2, 2);
	cout.precision(5);
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			//x[i][j] = round(dist(mt));
			//y[i][j] = round(dist(mt));
			x[i][j] = dist(mt);
			y[i][j] = dist(mt);
			z[i][j] = 0;
		}
	}
	cout << "First Matrix : " << endl;
	for (int i = 0; i<nn; i++)
	{
		cout << endl;
		for (int j = 0; j<nn; j++)
			cout << x[i][j] << "     ";
	}
	cout << endl;
	cout << endl<<"Second Matrix : " << endl;
	for (int i = 0; i<nn; i++)
	{
		cout << endl;
		for (int j = 0; j<nn; j++)
			cout << y[i][j] << "     ";
	}
	cout << endl;
	cout << endl<<"The Matrix by Strrassen Method : " << endl;
	create(nn,x,y,z);
	cout << endl;
	for (int i = 0; i < nn; i++)
	{
		delete[] x[i];
		delete[] y[i];
		delete[] z[i];
	}
	delete[] x;
	delete[] y;
	delete[] z;
}

//ttp://www.dreamincode.net/forums/topic/116381-strassens-multiplication/
