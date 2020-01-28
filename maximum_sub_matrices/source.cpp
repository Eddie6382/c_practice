#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>  //getline
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void ShowMatrix(int* matrix, int m, int n, int sub_m1, int sub_m2, int sub_n1, int sub_n2)
{
	if (sub_m1 == 0 && sub_m2 == 0 && sub_n1 == 0 && sub_n2 == 0)
		for (int i = 0; i < m; i++) 
        {
			for (int j = 0; j < n; j++)
				cout << *(matrix + i * n + j) << " ";
			cout << endl;
		}
	else
		for (int i = sub_m1; i <= sub_m2; i++)
		{
			for (int j = sub_n1; j <= sub_n2; j++)
				cout << *(matrix + i * n + j) << " ";
			cout << endl;
		}
}

int MaxSum(int* matrix, const int ROW, const int COL, int& sub_row1, int& sub_row2, int& sub_col1, int& sub_col2)
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
	int matrix[3][4] = { {-100,2,3,4} ,{5,100,7,8}, {-50,10,11,12} };
	ShowMatrix(*matrix, 3, 4, 0, 0, 0, 0);
	int sub_m1 = 0; 
	int sub_m2 = 0;
	int sub_n1 = 0;
	int sub_n2 = 0;
	MaxSum(*matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
	ShowMatrix(*matrix, 3, 4, sub_m1, sub_m2, sub_n1, sub_n2);
}