#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    const int arraysize = 7;
    int frequency[arraysize] = {};
    srand(time(0));
    for(int roll = 1; roll <= 6000; roll++){
        frequency[1+rand()%6] ++;
    }
    cout << "Face" << setw(13) << "Frequency" << endl;
    for(int i = 1; i <= 6; i++){
        cout << setw(4) << i << setw(13) << frequency[i] << endl;
    }
    return 0;
}