#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <random>
#include <cmath>

const int N = 3;

using namespace std;
int main()
{
	int i, j, k, n;

	random_device rd;
	mt19937 mt(rd());
	//uniform_real_distribution<double> dist(-10, 10);	//Use uniform distribution random variable
	normal_distribution<double> dist(5.0,2.0);

	double a[10][10] = { 0 }, d;

	n = N;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = ceil(dist(mt));
		}
	}
	for (i = 1; i <= n; i++) // i = 1 2 3
	{
		for (j = 1; j <= 2 * n; j++) // j = 1,2,3,4,5,6
		{
			if (j == (i + n)) //
			{
				a[i][j] = 1;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n * 2; j++)
		{
			cout << a[i][j] << "    ";
		}
		cout << endl;
	}
	//////////////////////////////////////////////
	for (i = n; i > 1; i--)
	{
		if (a[i - 1][1] < a[i][1])
		{
			for (j = 1; j <= n * 2; j++)
			{
				d = a[i][j];
				a[i][j] = a[i - 1][j];
				a[i - 1][j] = d;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n * 2; j++)
		{
			if (j != i)
			{
				d = a[j][i] / a[i][i];
				for (k = 1; k <= n * 2; k++)
				{
					a[j][k] = a[j][k] - (a[i][k] * d);
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		d = a[i][i];
		for (j = 1; j <= n * 2; j++)
		{
			a[i][j] = a[i][j] / d;
		}
	}
	cout << "Inverse Matrix " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = n + 1; j <= n * 2; j++)
		{
			cout << a[i][j] << "    ";
		}
		cout << endl;
	}
}