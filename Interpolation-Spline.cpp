# include <iostream>
# include <stdlib.h>
# include <string.h>
# include <math.h>

using namespace std;

const int max_size = 13;

int n = 0;
double s = 0;
double solution = 0;

long double an[max_size] = { 0 };
long double bn[max_size] = { 0 };
long double cn[max_size] = { 0 };
long double dn[max_size] = { 0 };

long double fx[max_size] = { 0 };
long double xn[max_size] = { 0 };

void show_screen();
void clear_screen();
void get_input();
void generate_natural_cubic_spline();
void show_natural_cubic_spline();

int main( )
{
	get_input();
	generate_natural_cubic_spline();
	show_natural_cubic_spline();

	return 0;
}
void get_input( )
{
	do
	{
		cout << "Number of Distinct Data Points [ min. n = 3  |  max. n = 12 ]" << endl;
		cout << "Enter the number of distinct data points : n = ";
		cin >> n;
		cout << endl;

		if (n<3 || n>12)
		{
			cout << "Error : Wrong Input. Press <Esc> to exit or any other key";
			cout << "        to try again.";
			cin >> n;
			if (n == 27)
				exit(0);
		}
	} while (n<3 || n>12);
	cout << endl;

	cout << "Data Points & Values of Function :";
	cout << endl;

	for (int i = 0; i<n; i++)
	{
		cout << "Enter the value of X : ";
		cin >> xn[i];
	}
	cout << endl;
	for (int count_2 = 0; count_2<n; count_2++)
	{
		cout << "Enter the value of Y : ";
		cin >> fx[count_2];
	}
	cout << endl;
	cout << "Enter the required value of X : ";
	cin >> s;
	cout << endl;
}

///-----------------  generate_natural_cubic_spline( )  ------------------
void generate_natural_cubic_spline( )
{
	// set ai=f(xi)     for i=0,1,2,3,...,n
	for (int i = 0; i < n; i++)
	{
		an[i] = fx[i];
	}

	long double temp_1[max_size] = { 0 };  
	long double temp_2[max_size]={0};      // ai
	long double temp_3[max_size]={0};      // li
	long double temp_4[max_size]={0};      // ui
	long double temp_5[max_size]={0};      // zi// set hi=x(i+1)-xi     for i=0,1,2,3,...,n-1
	for (int i = 0; i < (n - 1); i++)
	{
		temp_1[i] = (xn[i + 1] - xn[i]);
	}
	// set ai=(3/hi)*[a(i+1)-ai]-[3/h(i-1)]*[ai-a(i-1)]     for i=1,1,2,3,...,n-1
	for (int i = 1; i < (n - 1); i++)
	{
		temp_2[i] = (((3 / temp_1[i])*(an[(i + 1)] - an[i])) - ((3 / (temp_1[(i - 1)])*(an[i] - an[(i - 1)]))));
	}
	// set li0=1//     ui0=0//     zi0=0
	temp_3[0] = 1;
	temp_4[0] = 0;
	temp_5[0] = 0;

	// for i=1,1,2,3,...,n-1 ,set//    li=[2*{x(i+1)-x(i-1)}]-[h(i-1)*u(i-1)]//    ui=hi/li// zi=[ai-{h(i-1)*z(i-1)}]/li
	for (int i = 1; i < (n - 1); i++)
	{
		temp_3[i] = ((2 * (xn[(i + 1)] - xn[(i - 1)])) - (temp_1[(i - 1)] * temp_4[(i - 1)]));
		temp_4[i] = (temp_1[i] / temp_3[i]);
		temp_5[i] = ((temp_2[i] - (temp_1[(i - 1)] * temp_5[(i - 1)])) / temp_3[i]);
	}

	// set lin=1//     zin=0//     cn=0
	temp_3[(n - 1)] = 1;
	temp_5[(n - 1)] = 0;
	cn[(n - 1)] = 0;

	// for i=n-1,n-2,...,0   , set//     ci=zi-[ui*c(i+1)]//     bi=[a(i+1)-ai]/[hi-{hi*{c(i+1)+{2*ci}}/3]//     di=[c(i+1)-ci]/[3*hi]
	for (int i = (n - 2); i >= 0; i--)
	{
		cn[i] = (temp_5[i] - (temp_4[i] * cn[(i + 1)]));
		bn[i] = (((an[(i + 1)] - an[i]) / temp_1[i]) - ((temp_1[i] * (cn[(i + 1)] + (2 * cn[i]))) / 3));
		dn[i] = ((cn[(i + 1)] - cn[i]) / (3 * temp_1[i]));
	}
}

/*************************************************************************///--------------------  show_natural_cubic_spline( )  -------------------///*************************************************************************/
void show_natural_cubic_spline( )
{
	cout << "Natural Cubic Spline :" << endl;
	cout << endl;

	cout << "The required Cubic Polynomials are :" << endl;

	for (int count = 0; count<(n - 1); count++) //주의 !! X범위가 무조건 0부터 올라감
	{
		if ((s >= (double)count) && (s < (double)count + 1.0))
		{
			cout << "S" << count << "(x) =  ";

			long double aix = 0;
			long double bix = 0;
			long double cix = 0;
			long double dix = 0;

			aix = (an[count] - (bn[count] * xn[count]) + (cn[count] * powl(xn[count], 2)) - (dn[count] * powl(xn[count], 3)));
			bix = (bn[count] - (2 * cn[count] * xn[count]) + (3 * dn[count] * powl(xn[count], 3)));
			cix = (cn[count] - (3 * dn[count] * xn[count]));
			dix = dn[count];
			
			//cout << aix << " " << bix << " " << cix << " " << dix << endl;

			cout << aix;
			solution += aix;

			if (bix >= 0)
				cout << " + ";
			else
				cout << " - ";
			cout << fabsl(bix) << "x";
			solution += bix*s;

			if (cix >= 0)
				cout << " + ";
			else
				cout << " - ";
			cout << fabsl(cix) << "x2";
			solution += cix*pow(s,2);

			if (dix >= 0)
				cout << " + ";
			else
				cout << " - ";
			cout << fabsl(dix) << "x3";
			solution += dix*pow(s, 3);
			cout << endl;
		}
		else
		{
			cout << "S" << count << "(x) =  ";

			long double aix = 0;
			long double bix = 0;
			long double cix = 0;
			long double dix = 0;

			aix = (an[count] - (bn[count] * xn[count]) + (cn[count] * powl(xn[count], 2)) - (dn[count] * powl(xn[count], 3)));
			bix = (bn[count] - (2 * cn[count] * xn[count]) + (3 * dn[count] * powl(xn[count], 3)));
			cix = (cn[count] - (3 * dn[count] * xn[count]));
			dix = dn[count];

			cout << aix;

			if (bix >= 0)
				cout << " + ";
			else
				cout << " - ";

			cout << fabsl(bix) << "x";

			if (cix >= 0)
				cout << " + ";
			else
				cout << " - ";

			cout << fabsl(cix) << "x2";

			if (dix >= 0)
				cout << " + ";
			else
				cout << " - ";

			cout << fabsl(dix) << "x3";
			cout << endl;
		}
	}
	cout << "The value of function at X = " << s << " is " << solution << endl;
}
//http://www.dailyfreecode.com/code/construct-natural-cubic-spline-1076.aspx