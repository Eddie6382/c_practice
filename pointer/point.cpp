#include <iostream>
using namespace std;

int main(){
    int a;
    int* aPtr;

    a = 7;
    aPtr = &a;

    cout << "the address of a is " << &a << "\nthe value of aPtr is " << aPtr;
    cout << "\n\nThe value of a is " << a << "\nthe value of *aPtr is "<< *aPtr;
    cout << "\n\n& and * are inverse of each other: " << &*aPtr << " and " <<*&aPtr;

    return 0; 
}