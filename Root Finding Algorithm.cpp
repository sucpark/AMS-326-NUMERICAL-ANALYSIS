#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double initial_value_a = 1.5;
double initial_value_b = 1.55;
double tol = 0.00005;
int max_iteration_number = 10;

double f(double x)														//make function f
{
	return pow(2.016, -pow(x, 3)) - pow(x, 4)*sin(pow(x, 3)) - 1.949;
}
double f_prime(double x)												//make derivative of function f
{
	double y = 0;
	y = (-3 * pow(x, 2))*pow(2.016, -pow(x, 3)) - 4 * pow(x, 3)*sin(pow(x, 3)) - (3 * pow(x, 6))*cos(pow(x, 3));
	return y;
}
int sign_f(long double a)												//check the sign of value
{
	if (a < 0)
		return -1;
	else if (a>0)
		return +1;
	else
	{
		cout << "The value is 0. There is not sign" << endl;
		return 0;
	}
}
bool check_tol(double a, double b)										//check the tolerance to stop finding root iteration.
{
	if ((fabs(a - b) / fabs(a)) < tol)
		return true;
	else
		return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void Bisection_Method()
{
	cout.precision(10);													//to show more precise value
	cout << endl << "Start with the Bisection Method" << endl;
	cout << "The initial interval is [" << initial_value_a << " , " << initial_value_b << "]" << endl;		//I select initial interval based on the report
	cout << "The tolerance is " << tol << "and  the maximum iteration number is " << max_iteration_number << endl;			//Select tolerance and maximum iteration number to stop
	cout << "The initial function values are f(" << initial_value_a << ") = " << f(initial_value_a) << " , " << "f(" << initial_value_b << ") = " << f(initial_value_b) << endl; //To show that there must be root in the interval
	
	int n = 0;
	double p[20] = { 0 };
	double a = 0;
	double b = 0;
	
	a = initial_value_a;
	b = initial_value_b;
	p[0] = (a + b) / 2.0;

	cout << endl << "/////////////////////////////////////////////" << endl;
	cout << " p[0] is " << left << setw(11) << p[0] << " and f[p[0]] is " << f(p[0]) << endl;

	while (n <= max_iteration_number)								//if the number of iteration is higher than maximum iteration number, the process will be finish
	{
		if (sign_f(f(p[n])) == sign_f(f(a)))						//Check the sign of initial p
		{
			a = p[n];												//Since the sign of a and p is the same, the root must be in p and b. Set a new a by p
			n++;
			p[n] = (a + b) / 2.0;
			cout << " p[" << n << "] is " << setw(11) << p[n] << " and f[p(" << n << ")] is " << f(p[n]) << endl;
		}
		else
		{
			b = p[n];												//Since the sign of b and p is the same, the root must be in a and p. Set a new b by p
			n++;
			p[n] = (a + b) / 2.0;
			
			cout << " p[" << n << "] is " << setw(11) << p[n] << " and f[p(" << n << ")] is " << f(p[n]) << endl;
		}
		if (check_tol(p[n], p[n - 1]))							//From new p and previus p, we can check the stopping condition
		{
			break;
		}
	}
	cout.precision(5);											//The final result show with 4 digit.
	if (n == (max_iteration_number + 1))						//Case if the number of iteration is higher than 10
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The method is fail to find the root in 10 times" << endl;
		cout << " The last root is " << setw(5) << p[n-1] << endl << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
	else
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The root is " << setw(5) << p[n] << endl;
		cout << " f(" << p[n] << ") is " << f(p[n]) << endl << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Newton()
{
	int i = 1;
	double p0 = 0;
	double q0 = 0;
	double q0_ = 0;
	double p = 0;
	double q = 0;

	p0 = initial_value_a;
	q0 = f(p0);
	q0_ = f_prime(p0);						//Compute derivative of f 
	

	cout.precision(10);
	cout << " Start with the Newton Method" << endl;
	cout << " The initial root is " <<p0 << " and f[p(0)] is " << f(p0) << endl;
	cout << " The tolerance is " << tol << "and  the maximum iteration number is " << max_iteration_number << endl;
	cout << endl<<"/////////////////////////////////////////////" << endl;
	cout << " p[" << 0 << "] is " <<left<<setw(11)<< p0 << " and f(p(0)] is " << f(p0) << endl;
	while (i <= max_iteration_number)													//Stopping condition
	{
		p = p0 - (q0 / q0_);															//Compute a new p by using previus p, f(p) and f'(p)
		cout << " p[" << i << "] is " << setw(11) << p << " and f(p[" << i << "]) is " << f(p) << endl;
		if (check_tol(p,p0))															//Stopping condition
		{
			break;
		}
		else
		{
			i++;
			p0 = p;
			q0 = f(p);
			q0_ = f_prime(p);
		}
	}
	cout.precision(5);
	if (i == (max_iteration_number+1))
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The method is fail to find the root in 10 times" << endl;
		cout << " The last root is " << setw(5)<<p << endl << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
	else
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The root is " << p << endl;
		cout << "f(" << p << ") is " << f(p) << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
}
void Newton_Secant()													
{
	cout.precision(10);
	cout << " Start with the Newton_Secant Method" << endl;
	cout << " The initial interval is [" << initial_value_a << " , " << initial_value_b << "]" << endl;
	cout << " The initial function values are f(" << initial_value_a << ") = " << f(initial_value_a) << " , " << "f(" << initial_value_b << ") = " << f(initial_value_b) << endl;
	cout << " The tolerance is " << tol << "and  the maximum iteration number is " << max_iteration_number << endl;
	int i = 1;
	double p0 = 0;
	double p1 = 0;
	double q0 = 0;
	double q1 = 0;
	double p = 0;
	double q = 0;

	p0 = initial_value_a;									//Require two intial values
	p1 = initial_value_b;
	q0 = f(p0);
	q1 = f(p1);

	
	cout << endl<<"/////////////////////////////////////////////" << endl;
	cout << " p[" << 0 << "] is " << left<<setw(11)<<p0 << " and f(p[0]) is " << f(p0) << endl;

	while (i <= max_iteration_number)
	{
		p = p1 - q1*((p1 - p0) / (q1 - q0));							//Do not use a derivative of f.
		cout << " p[" << i << "] is " << setw(11) << p << " and f(p[" << i << "]) is " << f(p) << endl;
		if (check_tol(p,p1))										//Stopping condition
		{
			break;
		}
		i++;
		p0 = p1;
		q0 = q1;
		p1 = p;
		q1 = f(p);
	}
	cout.precision(5);
	if (i == max_iteration_number+1)
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The method is fail to find the root in 10 times" << endl;
		cout << " The last root is " << setw(5)<<p << endl << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
	else
	{
		cout << "/////////////////////////////////////////////" << endl << endl;
		cout << " The root is " <<setw(5)<< p << endl;
		cout << " f(" << p << ") is " << f(p) << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "/////////////////////////////////////////////" << endl << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void function_value()
{
	double p_value[100] = { 0 };
	initial_value_a = 0;
	initial_value_b = 0;

	double c = 0;
	cout << endl << "////////////////////////////////////////////////////////" << endl;
	cout << "Let's find an initial interval";
	cout << endl << "////////////////////////////////////////////////////////" << endl;
	p_value[0] = f(0);
	cout << " i = " << setw(4) << 0 << ", the value is " << f(0) << endl;
	for (int i = 1; i <= 100; i++)
	{
		c = 0 + i;
		cout << " i = " << setw(4) << c << ", the value is " << f(c) << endl;
		p_value[i] = f(c);
		if (p_value[i] * p_value[i - 1] < 0)
		{
			initial_value_a = c - 1;;
			initial_value_b = c;
			break;
		}
	}
	cout << endl << "////////////////////////////////////////////////////////" << endl;
	cout << "The initial interval is [" << initial_value_a << " , " << initial_value_b << "]" << endl;
	cout << "The initial function values are f(a) = " << f(initial_value_a) << " , " << "f(b) = " << f(initial_value_b);
	cout << endl << "////////////////////////////////////////////////////////" << endl;
}
void main()
{	
	function_value();
	Bisection_Method();
	Newton();
	Newton_Secant();
}
