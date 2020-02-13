#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>  //getline
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include "../usage.h"

using namespace std;

void ShowMatrix(const int* matrix, int m, int n, int sub_m1, int sub_m2, int sub_n1, int sub_n2)
{
	if (sub_m1 == 0 && sub_m2 == 0 && sub_n1 == 0 && sub_n2 == 0)
		for (int i = 0; i < m; i++) 
        {
			for (int j = 0; j < n; j++)
				cout << setw(4) << *(matrix + i * n + j);
			cout << endl;
		}
	else
		for (int i = sub_m1; i <= sub_m2; i++)
		{
			for (int j = sub_n1; j <= sub_n2; j++)
				cout << setw(4) << *(matrix + i * n + j);
			cout << endl;
		}
    cout << endl;
}

int MaxSum_brute(const int* matrix, int ROW, int COL, int& sub_row1, int& sub_row2, int& sub_col1, int& sub_col2)
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

int MaxSum(const int* matrix, const int ROW, const int COL, int& sub_row1, int& sub_row2, int& sub_col1, int& sub_col2)
{
	int global_max = INT8_MIN;
    for (int l_col = 0; l_col < COL; ++l_col)
        for (int r_col = l_col; r_col < COL; ++r_col) 
        {
            vector<int> row_array(ROW, 0);
            vector<int> local_max(ROW, 0);
            vector<int> local_row1(ROW, 0);
            for (int idx = 0; idx < ROW; ++idx) {
                for (int j = l_col; j <= r_col; ++j)
                    row_array[idx] +=  matrix[idx*COL + j];
            }

            local_max[0] = row_array[0];
            for (int idx = 1; idx < ROW; ++idx) {
                local_max[idx] = max(row_array[idx], row_array[idx] + local_max[idx-1]);
                local_row1[idx] = (local_max[idx] == row_array[idx]) ? idx : local_row1[idx-1];
                if (local_max[idx] > global_max)
                {
                    global_max = local_max[idx];
                    sub_row1 = local_row1[idx];
                    sub_row2 = idx;
                    sub_col1 = l_col;
                    sub_col2 = r_col;
                }
            }
        }

	cout << "maxSum:" << global_max << endl;
	return global_max;
}

void MakeMatrix(int* matrix, int ROW, int COL)
{
    random_device rd; //create psuedo random engine with rd as seed
	default_random_engine generator(rd());
	uniform_int_distribution<int> uniform(-100, 100); //create distiribution with output limited to 0~n
    for (int i = 0; i < ROW; ++i)
        for(int j = 0; j < COL; ++j)
            matrix[i*COL + j] = uniform(generator);
}

int main()
{
    int ROW, COL;
    cout << "please enter ROW and COL: ";
    cin >> ROW >> COL;

	int *matrix = new int[COL*ROW];
    MakeMatrix(matrix, ROW, COL);
	ShowMatrix(matrix, ROW, COL, 0, 0, 0, 0);
	int sub_m1 = 0; 
	int sub_m2 = 0;
	int sub_n1 = 0;
	int sub_n2 = 0;

    MyUsage usage;
    cout << "kadanes's algorithm: " << endl;
	MaxSum(matrix, ROW, COL, sub_m1, sub_m2, sub_n1, sub_n2);
	ShowMatrix(matrix, ROW, COL, sub_m1, sub_m2, sub_n1, sub_n2);
    usage.report(true, true);

    cout << "brute-force algorithm: " << endl;
    MaxSum_brute(matrix, ROW, COL, sub_m1, sub_m2, sub_n1, sub_n2);
	ShowMatrix(matrix, ROW, COL, sub_m1, sub_m2, sub_n1, sub_n2);
    usage.report(true, true);
}