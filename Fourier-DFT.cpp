#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double Pi = 3.141592;

void main()
{
	const int N = 16;
	double X[N] = { 0 };
	double realX[N] = { 0 };
	double imagX[N] = { 0 };
	
	random_device rd;
	mt19937 e2(rd());
	uniform_real_distribution<> dist(-1, 1);

	for (int i = 0; i < N; i++)	//Generate random discrete-time signal x in range (-1, 1)
	{
		X[i] = dist(e2);
		if (X[i] >= 0 && X[i]<=1)
			X[i] = X[i] - 1;
		else if (X[i]<0 && X[i]>=-1)
			X[i] = -X[i] - 1;
		else
			X[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			realX[i] += X[j] * cos(2 * Pi*j*i/N);
		}
		for (int j = 0; j < N; j++)
		{
			imagX[i] += X[j] * sin(2 * Pi*j*i / N);
		}
	}
	cout << "discrete time" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
	cout << "Transformed number " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << realX[i] << " + " << imagX[i] << "i" << endl;
	}
}