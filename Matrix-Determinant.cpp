#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;
const int nn = 3;

int addNum = 0;
int mulNum = 0;

void print(double b[nn][nn], int m)
{                        
	//cout << "MATRIX IS : "<<endl;	 //FUNCTION FOR PRINTING MATRIX
	//cout.precision(4);
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ", ";
		}
		cout << endl;
		//cout << i<<" = "<<b[i][0]<<endl; //Check the first value of each row
	}
}
double determinant(int m, double b[][nn])   //FUNCTION TO CALCULATE 
{
	int i=0, j=0;
	int m_ = m;
	//int numk = 0;
	double sum = 0;
	static double c[nn][nn] = { 0 };
	//cout << ++ numk << endl;
	if (m_== 2)
	{                                        //BASE CONDITION
		//cout << "M-==2" << endl << endl;
		addNum += 1;
		mulNum += 2;
		sum = b[0][0] * b[1][1] - b[0][1] * b[1][0];   //x-y = x + (-1)*y so, + = 1, * = 1
		return sum;
	}
	else if (m_ > 2)
	{
		for (int p = 0; p < m_; p++) //the first line of original matrix. (The line is used to multiply the inner determinant)
		{
			int h = 0, k = 0;	//new index for the minized new matrix.
			for (i = 1; i < m_; i++)
			{
				for (j = 0; j < m_; j++)
				{
					if (j == p)
					{

					}
					else
					{
						c[h][k] = b[i][j];
						k++;
						if (k == m_ - 1) //end of the matrix's column
						{
							h++;	//next row for new matrix
							k = 0;	//initialize the column number of the new matrix
						}
					}
				}
			}
			//cout << "/////////////////////////////" << endl;
			//print(c, m_ - 1);
			//cout << "////////////////////////////" << endl;
			addNum += 1;
			mulNum += 1;
			sum = sum + b[0][p] * pow(-1, p)*determinant(m_ - 1, c);
		}
		return sum;
	}
	else
	{
		cout << "Error" << endl;
		return 0;
	}
}
void main()
{
	static double b[nn][nn];
	static double result=0;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0, 1);
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			b[i][j] = dist(mt);
		}
	}
	double sum = b[0][0] * b[1][1] - b[0][1] * b[1][0];
	cout << "Let's Start!!!" << endl << endl;
	print(b, nn);
	result = determinant(nn, b);
	cout << endl<<"THE DETERMINANT OF THE ABOVE MATRIX IS : " << result << endl;
	cout << "Add count : " << addNum << ", Mul count : " << mulNum << endl;
}
