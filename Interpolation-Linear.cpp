#include <iostream>

using namespace std;

double linear_interpolation(double x0, double x1, double y0, double y1, double x=0)
{
	double a = (y1 - y0) / (x1 - x0);
	double b = -a*x0 + y0;
	double y = 0;
	cout << "The linear equation is " << "Y = " << a << "*X + " << b << endl;
	if (x != 0)
	{
		y = a*x + b;
		return y;
	}
	else
		return 0;
}

void main()
{
	int a = 0;
	double sol = 0;
	double solution = 0;
	int dummy = 0;
	cout << "Enter the number of the value :";
	cin >> a;
	
	double x[10] = { 0 };
	double y[10] = { 0 };
	cout << "Enter the value of x" << endl;
	for (int i = 0; i < a; i++)
	{
		cin >> x[i];
	}
	cout << "Enter the value of y" << endl;
	for (int i = 0; i < a; i++)
	{
		cin >> y[i];
	}
	cout << "Enter the required value of X to find f(X)" << endl;
	cin >> sol;
	cout << endl;

	cout << "Let's make a Linear interpolation equation" << endl << endl;
	for (int i = 0; i < a-1; i++)
	{
		if (sol >= i && sol < i + 1)
		{
			cout << "In the interval [" << x[i] << ", " << x[i + 1] << "],";
			cout << endl;
			solution=linear_interpolation(x[i], x[i + 1], y[i], y[i + 1],sol);
			cout << "////////////////////////////////////" << endl;
		}
		else
		{
			cout << "In the interval [" << x[i] << ", " << x[i + 1] << "],";
			cout << endl;
			dummy = linear_interpolation(x[i], x[i + 1], y[i], y[i + 1]);
			cout << "////////////////////////////////////" << endl;
		}
	}
	cout <<endl<< "The value of the function at " << sol << " is " << solution << endl;
}