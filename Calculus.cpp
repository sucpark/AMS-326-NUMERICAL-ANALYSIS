#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

double derive(double(*f)(double), double x0)
{
	const double delta = 1.0e-6; // or similar
	double x1 = x0 - delta;
	double x2 = x0 + delta;
	double y1 = f(x1);
	double y2 = f(x2);
	return (y2 - y1) / (x2 - x1);
}

void getlimit(double & lower, double & upper, int & imax)
{
	cout << "Enter the lower limit : " << endl;
	cin >> lower;
	cout << "Enter the upper limit : " << endl;
	cin >> upper;
	cout << "Enter the maximum number of iterations allowed: " << endl;
	cin >> imax;
}
double trapezoid(double(*f)(double), double a, double b, int imax)
{
	double r, dx, x;
	r = 0.0;
	dx = (b - a) / (double)imax;

	for (int i = 1; i <= imax - 1; i++)
	{
		x = a + double(i*dx);
		r = r + f(x);
	}
	r = (r + (f(a) + f(b)) / 2.0)*dx;
	return r;
}
double trape(double(*f)(double), double a, double b, int imax)
{
	double r, dx, x,x_;
	r = 0;
	double sum = 0;
	dx = (b - a) / imax;

	for (int i = 0; i < imax; i++)
	{
		x_ = a + i*dx;
		x = x_+dx;
		r = f(x);
		sum = sum + (dx*(f(x_)+f(x)))/2.0;
	}
	sum = sum * 2;
	return sum;
}
double simpson(double(*f)(double),double a, double b, int imax)
{
	double s, dx, x;
	if ((imax / 2.0) * 2 != imax)
	{
		imax = imax + 1;
	}
	s = 0.0;
	dx = (b - a) / (double)imax;
	for (int i = 2; i <= imax - 1; i = i + 2)
	{
		x = a + (double)(i*dx);
		s = s + 2.0*f(x) + 4.0*f(x + dx);
	}
	s = (s + f(a) + f(b) + 4.0*f(a + dx))*dx / 3.0;
	return s;
}
double random_uniform()
{
	return double(rand()) / double(RAND_MAX);
}
double MonteCarloIntegral1D(double(*f)(double), double a, double b, int n)
{
	double u, x;
	double sum = 0.0;
	double avgValue;

	srand((unsigned int)time(0));

	for (int i = 1; i <= n; i++)
	{
		u = random_uniform();
		x = a + (b - a)*u;
		sum = sum + f(x);
		avgValue = sum / n;
	}

	double answer = (b - a)*avgValue;
	return answer;
}
double func1(double x)
{
	return x*x;
}
double func2(double x)
{
	return 1 / (x+1);
}
double func3(double x)
{
	return sin(x);
}
double func4(double x)
{
	return sqrt(1.2345*1.2345 - x*x);
}
double func5(double x)
{
	double k = pow(x, 3) + x + 9 * x - 14;
	return k;
}
///////////////////////////////////////////////////////////////////////////////////////
void main()
{
	string str1 = "x^2";
	string str2 = "1/(x+1)";
	string str3 = "sinx";
	string str4 = "sqrt(1.2345^2-x^2)";
	double(*f)(double) = 0;
	double lower=0, upper=0, integraValue=0, deriviativeValue=0, num=0;
	int method=0, imax=0, equation = 0;;
	
	const int PICK_EQUATION = 4;
	const int MAXETHODS = 4;

	while (equation != 5)
	{
		cout << "Please chose from an equation below:" << endl;
		cout << "1 : " << str1 << endl;
		cout << "2 : " << str2 << endl;
		cout << "3 : " << str3 << endl;
		cout << "4 : " << str4 << endl;
		cout << "5 : Exit the menu " << endl;
		cin >> equation;
		if (equation == 1)
			f = func1;
		else if (equation == 2)
			f = func2;
		else if (equation == 3)
			f = func3;
		else if (equation == 4)
			f = func4;
		else
			break;
		cout << "Pick your method of choice : " << endl;
		cout << "1 : Trapezoidal Rule(Integration)" << endl;
		cout << "2 : Simpson's method(Integration)" << endl;
		cout << "3 : MonteCarlo method(Integration)" << endl;
		cout << "4 : Derivation" << endl;
		cin >> method;

		if (method <= MAXETHODS)
		{
			switch (method)
			{
			case 1:
				getlimit(lower, upper, imax);
				integraValue = trapezoid(f, lower, upper, imax);
				cout << "The value of the integra is " << integraValue << endl;
				break;
			case 2:
				getlimit(lower, upper, imax);
				integraValue = simpson(f, lower, upper, imax);
				cout << "The value of the integra is " << integraValue << endl;
				break;
			case 3:
				getlimit(lower, upper, imax);
				integraValue = MonteCarloIntegral1D(f, lower, upper, imax);
				cout << "The value of the integra is " << integraValue << endl;
				break;
			case 4:
				cout << "Enter the point :";
				cin >> num;
				deriviativeValue = derive(f, num);
				cout << "The value of the derivative is " << deriviativeValue << endl;
				break;
			}
		}
		cout << endl << "///////////////////////////////////" << endl << endl;
	}
}

//ttp://forums.devarticles.com/c-c-help-52/help-c-menu-numerical-integration-177465.html