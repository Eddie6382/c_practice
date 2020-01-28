#include <iostream>
#include "complex.h"
#include <math.h>
#define PI = 3.1415926
using namespace std;

int main()
{
    Complex a, b, c;
    cout << "solving a*z^2 + b*z + c = 0: \nplease enter a, b, c in cpmplex form (no space)" << endl;
    cin >> a >> b >> c;

    Complex temp = (b * b - (a * c) * 4) / ((a * a) * 4);
    Complex out_1, out_2;
    sqrt(temp, out_1, out_2);
    cout << "x + b/2a =  ";
    cout << out_1 << ", " << out_2 << endl;
    cout << "-b / (a*2) =  ";
    cout << -b / (a * 2) << endl;
    cout << "2 roots are:\n ";
    cout << -b / (a * 2) + out_1 << endl;
    cout << -b / (a * 2) + out_2 << endl;

    return 0;
}