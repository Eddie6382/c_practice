#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
    unsigned seed;

    cout << "Enter seed: ";
    cin >> seed;     //seed id important
    srand(seed);
    for(int count=1; count<=10; count++)
    {
        cout << setw(10) << (1+rand()%6);
        if (count%5 == 0)
        {
            cout << endl;
        }
    }
    return 0;
}