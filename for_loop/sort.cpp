#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int arraysize = 10;
    int data[ arraysize ] = { 34,56,4,10,77,51,93,30,5,52 };
    int insert;

    cout << "Unsort array:";
    for (int i = 0; i < arraysize; i++){
        cout << setw(4) << data[i];
    }
    cout << '\n';
    // loop over the element the element of the array
    for (int next = 1; next < arraysize; next++){
        insert = data[next];
        int moveitem = next;
        while((moveitem > 0) && ( data[moveitem-1] > insert )){
            data[moveitem] = data[moveitem-1];
            moveitem--;
        }
        data[moveitem] = insert;
        cout << "after state" << next << ":";
        for (int i = 0; i < arraysize; i++){
            cout << setw(4) << data[i];
        }
        cout << '\n';
    }
    return 0;
}