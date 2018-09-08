#include<iostream>
#include<cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};

void leastSqrRegression(struct Point* xyCollection, int dataSize)
{
	if (xyCollection == NULL || dataSize == 0)
	{
		printf("Empty data set!\n");
		return;
	}

	double SUMx = 0;     //sum of x values
	double SUMy = 0;     //sum of y values
	double SUMxy = 0;    //sum of x * y
	double SUMxx = 0;    //sum of x^2
	double SUMres = 0;   //sum of squared residue
	double res = 0;      //residue squared
	double slope = 0;    //slope of regression line
	double y_intercept = 0; //y intercept of regression line
	double SUM_Yres = 0; //sum of squared of the discrepancies
	double AVGy = 0;     //mean of y
	double AVGx = 0;     //mean of x
	double Yres = 0;     //squared of the discrepancies
	double Rsqr = 0;     //coefficient of determination

	//calculate various sums 
	for (int i = 0; i < dataSize; i++)
	{
		//sum of x
		SUMx = SUMx + (xyCollection + i)->x;
		//sum of y
		SUMy = SUMy + (xyCollection + i)->y;
		//sum of squared x*y
		SUMxy = SUMxy + (xyCollection + i)->x * (xyCollection + i)->y;
		//sum of squared x
		SUMxx = SUMxx + (xyCollection + i)->x * (xyCollection + i)->x;
	}

	//calculate the means of x and y
	AVGy = SUMy / dataSize;
	AVGx = SUMx / dataSize;

	//slope or a1
	slope = (dataSize * SUMxy - SUMx * SUMy) / (dataSize * SUMxx - SUMx*SUMx);

	//y itercept or a0
	y_intercept = AVGy - slope * AVGx;

	printf("x mean(AVGx) = %0.5E\n", AVGx);
	printf("y mean(AVGy) = %0.5E\n", AVGy);

	printf("\n");
	printf("The linear equation that best fits the given data:\n");
	printf("       y = %2.8lfx + %2.8f\n", slope, y_intercept);
	printf("------------------------------------------------------------\n");
	printf("   Original (x,y)   (y_i - y_avg)^2     (y_i - a_o - a_1*x_i)^2\n");
	printf("------------------------------------------------------------\n");

	//calculate squared residues, their sum etc.
	for (int i = 0; i < dataSize; i++)
	{
		//current (y_i - a0 - a1 * x_i)^2
		Yres = pow(((xyCollection + i)->y - y_intercept - (slope * (xyCollection + i)->x)), 2);

		//sum of (y_i - a0 - a1 * x_i)^2
		SUM_Yres += Yres;

		//current residue squared (y_i - AVGy)^2
		res = pow((xyCollection + i)->y - AVGy, 2);

		//sum of squared residues
		SUMres += res;

		printf("   (%0.2f %0.2f)      %0.5E         %0.5E\n",
			(xyCollection + i)->x, (xyCollection + i)->y, res, Yres);
	}

	//calculate r^2 coefficient of determination
	Rsqr = (SUMres - SUM_Yres) / SUMres;

	printf("--------------------------------------------------\n");
	printf("Sum of (y_i - y_avg)^2 = %0.5E\t\n", SUMres);
	printf("Sum of (y_i - a_o - a_1*x_i)^2 = %0.5E\t\n", SUM_Yres);
	printf("Standard deviation(St) = %0.5E\n", sqrt(SUMres / (dataSize - 1)));
	printf("Standard error of the estimate(Sr) = %0.5E\t\n", sqrt(SUM_Yres / (dataSize - 2)));
	printf("Coefficent of determination(r^2) = %0.5E\t\n", (SUMres - SUM_Yres) / SUMres);
	printf("Correlation coefficient(r) = %0.5E\t\n", sqrt(Rsqr));
}
void main()
{
	Point a[5] = { 0 };
	a[0].x = 1;
	a[0].y = 3652;
	a[1].x = 2;
	a[1].y = 3539;
	a[2].x = 3;
	a[2].y = 3023;
	a[3].x = 4;
	a[3].y = 2880;
	a[4].x = 5;
	a[4].y = 2737;
	leastSqrRegression(a, 5);
}

//ttp://codesam.blogspot.com/2011/06/least-square-linear-regression-of-data.html