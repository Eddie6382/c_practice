// compare three methods to pass arguments to function
#include <iostream>
using namespace std;

int pass_by_value(int);
void reference_argument(int &);
void pass_by_reference(int *);


int main(){
    int n1 = 5, n2 = 5, n3 =5;
    int m = 2;
    int r = 3;

    //nonconstant pointer to constant data, can change the destination of pointer
    const int *yPtr = &m;     
    cout << yPtr << endl;
    yPtr = &r;
    cout << yPtr << endl;

    //constant pointer to nonconstant data, only can change the value of data
    int * const xPtr = &m;
    cout << *xPtr << endl;
    *xPtr = 5;
    cout << *xPtr << endl;

    //nonconstant to nonconstant
    int a = 6, b = 7;
    int *aPtr = &a;
    *aPtr = 5;   //directly modify the value of a
    cout << "*aPtr: " << *aPtr << " a: "  << a << endl;


    pass_by_value(n1);
    cout << "pass by value, n1 = " << n1 << endl;
    reference_argument(n2);
    cout << "reference_argument, n2: "<< n2 << endl;
    pass_by_reference(&n3);
    cout << "pass by reference, n3: "<< n3 << endl;
    return 0; 
}

int pass_by_value(int n){
    n = n*n*n;
    return n;
}

void reference_argument(int &n){
    n = n*n*n;
}

void pass_by_reference(int *n){
    *n = *n * *n * *n;
}
