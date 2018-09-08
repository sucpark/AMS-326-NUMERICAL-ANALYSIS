// Name : Suchan Park
// Stonybrook ID : 110650430
// The course : AMS326
// The assignment name and number : Homework 02_2

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(-10.0, 10.0);	//Compute uniform random variable

	const int iteration = 100000000;
	const int interval = 20;
	const int new_length = iteration / interval;
	int count_num[20] = { 0 };
	int count_num2[20] = { 0 };
	int total = 0;
	int total2 = 0;
	int cnt = 1;
	double sum = 0;
	double average_percentage = 0;
	static double g[new_length] = { 0 };  //We need to define static variable because stack memory is not enough to make array with the length
	cout << "Uniform_distribution (-10.0, 10.0)" << endl;
	for (int i = 1; i <= iteration; i++)
	{
		double m = dist(mt);	//Problem 2.2 (1) We can make the number that uniformly distribute in (-10,10)
		sum += m;
		if ((i / 20) == cnt)	//Problem 2.2 (4) Make the new variable, Y => sum of the 20 uniform distribution numbers
		{
			g[cnt - 1] = sum;
			sum = 0;
			cnt++;
		}
		if ((m>=-10) && (m<=-9))	//Problem 2.2 (2) Record the number's interval. We can use it to count the percentages of the numbers that belong to such interval;
			count_num[0]++;
		else if ((m>-9) && (m <= -8))
			count_num[1]++;
		else if ((m>-8) && (m <= -7))
			count_num[2]++;
		else if ((m>-7) && (m <= -6))
			count_num[3]++;
		else if ((m>-6) && (m <= -5))
			count_num[4]++;
		else if ((m>-5) && (m <= -4))
			count_num[5]++;
		else if ((m>-4) && (m <= -3))
			count_num[6]++;
		else if ((m>-3) && (m <= -2))
			count_num[7]++;
		else if ((m>-2) && (m <= -1))
			count_num[8]++;
		else if ((m>-1) && (m <= 0))
			count_num[9]++;
		else if ((m>0) && (m <= 1))
			count_num[10]++;
		else if ((m>1) && (m <= 2))
			count_num[11]++;
		else if ((m>2) && (m <= 3))
			count_num[12]++;
		else if ((m>3) && (m <= 4))
			count_num[13]++;
		else if ((m>4) && (m <= 5))
			count_num[14]++;
		else if ((m>5) && (m <= 6))
			count_num[15]++;
		else if ((m>6) && (m <= 7))
			count_num[16]++;
		else if ((m>7) && (m <= 8))
			count_num[17]++;
		else if ((m>8) && (m <= 9))
			count_num[18]++;
		else if ((m>9) && (m <= 10))
			count_num[19]++;
		else
			cout << "Error" << endl;
	}
	for (int i = 0; i < 20; i++)
		total += count_num[i]; //To compute the percantage of each interval
	for (int i = 0; i < new_length; i++)
	{
		if ((g[i] >= -200) && (g[i] <= -180))
			count_num2[0]++;
		else if ((g[i]>-180) && (g[i] <= -160))
			count_num2[1]++;
		else if ((g[i]>-160) && (g[i] <= -140))
			count_num2[2]++;
		else if ((g[i]>-140) && (g[i] <= -120))
			count_num2[3]++;
		else if ((g[i]>-120) && (g[i] <= -100))
			count_num2[4]++;
		else if ((g[i]>-100) && (g[i] <= -80))
			count_num2[5]++;
		else if ((g[i]>-80) && (g[i] <= -60))
			count_num2[6]++;
		else if ((g[i]>-60) && (g[i] <= -40))
			count_num2[7]++;
		else if ((g[i]>-40) && (g[i] <= -20))
			count_num2[8]++;
		else if ((g[i]>-20) && (g[i] <= 0))
			count_num2[9]++;
		else if ((g[i]>0) && (g[i] <= 20))
			count_num2[10]++;
		else if ((g[i]>20) && (g[i] <= 40))
			count_num2[11]++;
		else if ((g[i]>40) && (g[i] <= 60))
			count_num2[12]++;
		else if ((g[i]>60) && (g[i] <= 80))
			count_num2[13]++;
		else if ((g[i]>80) && (g[i] <= 100))
			count_num2[14]++;
		else if ((g[i]>100) && (g[i] <= 120))
			count_num2[15]++;
		else if ((g[i]>120) && (g[i] <= 140))
			count_num2[16]++;
		else if ((g[i]>140) && (g[i] <= 160))
			count_num2[17]++;
		else if ((g[i]>160) && (g[i] <= 180))
			count_num2[18]++;
		else if ((g[i] > 180) && (g[i] <= 200))
			count_num2[19]++;
		else
			cout << "Error" << endl;
	}
	for (int i = 0; i < 20; i++)
		total2 += count_num2[i]; //To compute the percantage of each interval

	cout.precision(5);
	cout << "Compute the uniformly distributed random number percentage!!!" << endl;
	for (int i = 0; i < 19; i++)	//Problem2.2 (2) Print the percentage of the interval.
	{
		double k = (count_num[i] / (double)total)*100;
		cout << "Interval (" << setw(3) << -10 + i << ", " << setw(3) << -9 + i << "], the percentage of number is " << k << " %" << endl;
		average_percentage += k;
	}
	cout << "Interval (  " << 9 << ",  " << 10 << "), the percentage of number is " << (count_num[19] / (double)total) * 100 << " %" << endl;
	average_percentage += (count_num[19] / (double)total)*100;
	cout << "The arithmetic average of the percentages is " << average_percentage / 20.0 << endl;  //Problem 2.2 (3) Compute the average of the percentages.
	
	cout << endl << "//////////////////////////////////////////////////////" << endl<<endl;
	for (int i = 0; i < 19;i++)
	{
		cout << "The g-number for interval (" << setw(3) << -10 + i << ", " << setw(3) << -9 + i << "] is " << count_num2[i]<<endl;
	}
	cout << "The g-number for interval (" << setw(3) << 9 << ", " << setw(3) << 10 << ") is " << count_num2[19] << endl << endl;

	cout << "Compute the new random number percentage!!!" << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << "Interval (" << setw(3) << -10 + i << ", " << setw(3) << -9 + i << "], the percentage of number is " << (count_num2[i] / (double)total2) * 100 << " %" << endl;
	}
	cout << "Interval (  " << 9 << ",  " << 10 << "), the percentage of number is " << (count_num2[19] / (double)total2) * 100 << " %" << endl;
	cout << endl << "//////////////////////////////////////////////////////" << endl;
}
