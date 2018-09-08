#include <iostream>
#include <random>

using namespace std;

void main()
{
	double A[10][10] = { 0 }, L[10][10] = { 0 }, U[10][10];
	double B[10] = { 0 }, X[10] = { 0 }, Y[10] = { 0 };
	double mult[10][10] = { 0 };
	int i, j,k, n;
	n = 3;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0, 9);	//Use uniform distribution random variable
	//normal_distribution<double> dist(0, 5.0);

	cout << endl << "Print matrix element: " << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			A[i][j] = (int)dist(mt);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n ; j++)
		{
			cout << A[i][j] << "    ";
		}
		cout << endl;
	}

	cout << endl << "Print the constant terms: " << endl;
	for (i = 0; i<n; i++)
	{
		B[i] = (int)dist(mt);
	}
	for (i = 0; i<n; i++)
	{
		cout << B[i] << endl;
	}
	////////////////////////////////////////////////////
	double sub = 0;
	for (j = 0; j < n-1; j++)
	{
		for (int g = 1; g < n-j; g++)
		{
			sub = A[j + g][j] / A[j][j];
			for (i = 0; i < n; i++)
			{
				A[j + g][i] -= sub*A[j][i];
			}

			B[j + g] -= sub*B[j];
			L[j][j] = 1;
			L[j + g][j] = sub;
		}
	}
	L[n - 1][n - 1] = 1;

	cout << "[L] : " << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			cout<<L[i][j]<<"\t";
		cout << endl;
	}
	cout << endl << endl << "[U] : " << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
	////////////////////////////////////////////////////////////
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			for (k = 0; k < n; ++k)
			{
				mult[i][j] += L[i][k] * A[k][j];
			}
		}
	}
	cout << "[L][U] : " << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			cout << mult[i][j] << "\t";
		cout << endl;
	}

	double d = 0;
	for (i = 0; i <n; i++)
	{
		for (j = 0; j < 2 * n; j++)
		{
			if (j == (i + n))
			{
				mult[i][j] = 1;
			}
		}
	}
	/////////////////////////////////////////
	cout << "/////////////////////////" << endl;
	cout << "Augmented Matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n * 2; j++)
		{
			cout << mult[i][j] << "    ";
		}
		cout << endl;
	}
	cout << "////////////////////////" << endl;
	//////////////////////////////////
	/*
	for (i = n-1; i > 0; i--)
	{
		if (mult[i - 1][0] < mult[i][0])
		{
			for (j = 0; j < n * 2; j++)
			{
				d = mult[i][j];
				mult[i][j] = mult[i - 1][j];
				mult[i - 1][j] = d;
			}
		}
	}
	*/

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n * 2; j++)
		{
			if (j != i)
			{
				d = mult[j][i] / mult[i][i];
				for (k = 0; k < n * 2; k++)
				{
					mult[j][k] = mult[j][k] - (mult[i][k] * d);
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		d = mult[i][i];
		for (j = 0; j < n * 2; j++)
		{
			mult[i][j] = mult[i][j] / d;
		}
	}
	cout << "Inverse Matrix " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = n; j < n * 2; j++)
		{
			cout << mult[i][j] << "    ";
		}
		cout << endl;
	}
	//ttp://www.sanfoundry.com/cpp-program-finds-inverse-graph-matrix/
			///////////////////////////////////////
	cout << endl << endl << endl;
	for (i = 0; i<n; i++)
	{
		Y[i] = B[i];
		for (j = 0; j<i; j++)
		{
			Y[i] -= L[i][j] * Y[j];
		}
	}
	cout << "[Y]: " << endl;
	for (i = 0; i<n; i++)
	{
		cout << Y[i] << " ";
	}
	for (i = n - 1; i >= 0; i--)
	{
		X[i] = Y[i];
		for (j = i + 1; j<n; j++)
		{
			X[i] -= U[i][j] * X[j];
		}
		X[i] = X[i]/U[i][i];
	}
	cout << endl<<"[X] : " << endl;
	for (i = 0; i<n; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
}

