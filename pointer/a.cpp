#include <iostream>
using namespace std;

int main(){
    int v[3] = {1,2,3};
    cout << sizeof(v[0]) << endl;
    int (*q)[3] = &v;
    for(int i=0; i<3; i++){
        cout << (*q)[i] << ' ';
    }
    cout << '\n';

    int *r[3] = {&v[2], &v[1], &v[0]};
    for(int j=0; j<3; j++){
        cout << *r[j] << ' ';
    }
    return 0;
}