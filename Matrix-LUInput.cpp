#include <iostream>

using namespace std;

void main()
{
	double A[20][20] = { 0 }, L[20][20] = { 0 }, U[20][20];
	double B[20] = { 0 }, X[20] = { 0 }, Y[20] = { 0 };
	int i, j, n;

	cout << "Enter the order of square matrix: ";
	cin >> n;
	cout << endl << "Enter matrix element: " << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << "Enter A[" << i << "][" << j << "] element: ";
			cin>>A[i][j];
		}
	}
	cout << endl << "Enter the constant terms: " << endl;
	for (i = 0; i<n; i++)
	{
		cout<<"B["<<i<<"] : ";
		cin>>B[i];
	}
	////////////////////////////////////////////////////
	double k = 0;
	//k = A[0][0];
	//A[0][0] = A[0][0] / k;
	//A[0][1] = A[0][1] / k;
	//A[0][2] = A[0][2] / k;
	//A[0][3] = A[0][3] / k;
	//B[0] = B[0] / k;

	double sub = 0;

	sub = A[1][0] / A[0][0];
	A[1][0] -= sub*A[0][0];
	A[1][1] -= sub*A[0][1];
	A[1][2] -= sub*A[0][2];
	A[1][3] -= sub*A[0][3];
	B[1] -= sub*B[0];
	L[0][0] = 1;
	L[1][0] = sub;
	sub = A[2][0] / A[0][0];
	A[2][0] -= sub*A[0][0];
	A[2][1] -= sub*A[0][1];
	A[2][2] -= sub*A[0][2];
	A[2][3] -= sub*A[0][3];
	B[2] -= sub*B[0];
	L[2][0] = sub;
	sub = A[3][0] / A[0][0];
	A[3][0] -= sub*A[0][0];
	A[3][1] -= sub*A[0][1];
	A[3][2] -= sub*A[0][2];
	A[3][3] -= sub*A[0][3];
	B[3] -= sub*B[0];
	L[3][0] = sub;

	//k = A[1][1];
	//A[1][1] = A[1][1] / k;
	//A[1][2] = A[1][2] / k;
	//A[1][3] = A[0][3] / k;
	//B[1] = B[1] / k;

	sub = A[2][1] / A[1][1];
	A[2][1] -= sub*A[1][1];
	A[2][2] -= sub*A[1][2];
	A[2][3] -= sub*A[1][3];
	B[2] -= sub*B[1];
	L[1][1] = 1;
	L[2][1] = sub;
	sub = A[3][1] / A[1][1];
	A[3][1] -= sub*A[1][1];
	A[3][2] -= sub*A[1][2];
	A[3][3] -= sub*A[1][3];
	B[3] -= sub*B[1];
	L[3][1] = sub;

	//k = A[2][2];
	//A[2][2] = A[2][2] / k;
	//A[2][3] = A[2][3] / k;
	//B[2] = B[2] / k;
	sub = A[3][2] / A[2][2];
	A[3][2] -= sub*A[2][2];
	A[3][3] -= sub*A[2][3];
	B[3] -= sub*B[2];
	L[2][2] = 1;
	L[3][2] = sub;
	L[3][3] = 1;
	/*
	for (j = 0; j<n; j++)
	{
		for (i = 0; i<n; i++)
		{
			if (i <= j)
			{
				U[i][j] = A[i][j];
				for (k = 0; k<i - 1; k++)
					U[i][j] -= L[i][k] * U[k][j];
				if (i == j)
					L[i][j] = 1;
				else
					L[i][j] = 0;
			}
			else
			{
				L[i][j] = A[i][j];
				for (k = 0; k <= j - 1; k++)
					L[i][j] -= L[i][k] * U[k][j];
				L[i][j] =L[i][j]/U[j][j];
				U[i][j] = 0;
			}
		}
	}
	*/
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

