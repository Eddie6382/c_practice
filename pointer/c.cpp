#include<iostream>
using namespace std;

void print(int *v, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << *(v + i*height + j) << ' ';
        }
        cout << '\n';
    }
}

int main(){
    int v[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    print((int *)v, 3, 3);
    return 0;
}