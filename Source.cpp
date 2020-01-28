#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>  //getline
#include <string>
#include <limits>

using namespace std;

void ShowMatrix(int* matrix, int m, int n, int sub_m1, int sub_m2, int sub_n1, int sub_n2);
int MaxSum(int* matrix, int m, int n, int& sub_m1, int& sub_m2, int& sub_n1, int& sub_n2);
void MakeMatrix(int m, int n, int* matrix);

int main()
{
	/*
	do {
		MaxSubMatrix();
	} while (AskYesOrNo("Do you want to start a new game?"));
	*/
	int matrix[3][4] = { {-100,2,3,4} ,{5,100,7,8}, {-50,10,11,12} };
	ShowMatrix(*matrix, 3, 4, 0, 0, 0, 0);
	int sub_m1 = 0; 
	int sub_m2 = 0;
	int sub_n1 = 0;
	int sub_n2 = 0;
	MaxSum(*matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
	ShowMatrix(*matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
	/*
	int *matrix = new int[3, 4];
	MakeMatrix(3, 4, matrix);
	ShowMatrix(matrix, 3, 4, 0, 0, 0, 0);
	int sub_m1, sub_m2, sub_n1, sub_n2;
	MaxSum(matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
	ShowMatrix(matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
	*/
}

void ShowMatrix(int* matrix, int m, int n, int sub_m1, int sub_m2, int sub_n1, int sub_n2)
{
	if (sub_m1 == 0 && sub_m2 == 0 && sub_n1 == 0 && sub_n2 == 0)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << *(matrix + i * n + j) << " ";
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = sub_m1; i <= sub_m2; i++)
		{
			for (int j = sub_n1; j <= sub_n2; j++)
			{
				cout << *(matrix + i * n + j) << " ";
			}
			cout << endl;
		}
	}
}
int MaxSum(int* matrix, int ROW, int COL, int& sub_row1, int& sub_row2, int& sub_col1, int& sub_col2)
{
	int max = INT8_MIN;
	for (int pivot_row = 0; pivot_row < ROW; ++pivot_row)
		for (int pivot_col = 0; pivot_col < COL; ++pivot_col)
			for (int i = pivot_row; i < ROW; ++i)
				for (int j = pivot_col; j < COL; ++j)
				{
					// for every sub matrices in the matrix, find the sum of each sub matrices
					int sum = 0;
					for (int r = pivot_row; r <= i; ++r)
						for (int s = pivot_col; s <= j; ++s)
							sum += matrix[r*COL + s];
					if (sum > max) {
						sub_row1 = pivot_row;
						sub_row2 = i;
						sub_col1 = pivot_col;
						sub_col2 = j;
						max = sum;
					}
				}
	cout << "maxSum:" << max << endl;
	return max;
}
int RandomInput()
{
	random_device rd; //create psuedo random engine with rd as seed
	default_random_engine generator(rd());
	uniform_int_distribution<int> uniform(-100, 100); //create distiribution with output limited to 0~n
	return uniform(generator);
}

void MakeMatrix(int m, int n, int* matrix)
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(matrix + i * n + j) = RandomInput();
		}
	}
}