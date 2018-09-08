#include <iostream>

using namespace std;
#define MAX 200
/**************************************************************/
/* Lagranges interpolation formula */
/*
Y=(x-X2)(x-X3)...(x-Xn)/(X1-X2)(X1-X3)...(X1-Xn)*y[1]
+(x-X1)(x-X3)...(x-Xn)/(X2-X2)(X2-X3)...(X2-Xn)*y[2]
+...+
(x-X1)(x-X2)...(x-X(n-1))/(Xn-X1)(Xn-X2)...(Xn-X(n-1))*y[n]
*/
/*************************************************************/
void main()
{
	int n, i, j;
	n = 0;
	double x[MAX], f[MAX], fp, lf, sum, xp;

	cout << "LAGRANGE'S INTERPOLATION METHOD " << endl;

	cout << "ENTER THE TOTAL NUMBER OF POINT FOR INTERPOLATION: ";
	cin >> n;
	while (n <= 0 || n > 200)
	{
		if (n <= 0)
			cout << "NUMBER OF POINT FOR INTERPOLATION MUST BE POSITIVE" << endl;
		else if (n > 200)
			cout << " THIS PROGRAM IS NOT CAPABLE TO ACCEPT THIS VALUE" << endl;
		cout << "ENTER THE TOTAL NUMBER OF POINT FOR INTERPOLATION: ";
		cin >> n;
	}
	cout << "ENTER THE VALUE OF x & THE CORRESPONDING VALUES OF f(x)" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "ENTER THE VALUE OF x"<<i<<" = ";
		cin>>x[i];
		cout <<"ENTER THE VALUE OF f(x"<<i<<") = ";
		cin>>f[i];
	}
	cout << "ENTER THE VALUE OF x AT WHICH INTERPOLATION IS REQUIRED: ";
	cin>>xp;
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		lf = 1.0;
		for (j = 0; j < n; j++)
		{
			if (i != j)
				lf = lf*(xp - x[j]) / (x[i] - x[j]);
		}
		sum = sum + lf*f[i];
	}
	fp = sum;
	cout << "The required interpolation value at x = " << xp << " is " << fp << endl;
	cout << "--------------------------------------------------------------" << endl;
}
//http://www.mycomputerscience.net/2012/10/c-program-implement-lagranges-interpolation-method.html#