#include<iostream>
using namespace std;

void print(int (*q)[4]){
    for(int i = 0; i < sizeof(*q)/sizeof((*q)[0]); i++){
        cout << (*q)[i] << ' ';
    }
}

int main(){
    int v[] = {1,2,3,4};
    print(&v);
    return 0;
}