#include<stdio.h>
#include<stdlib.h>
void Hanoi(int, int, int, int);
void Hanoi(int n, int s, int m, int d){
    if(n==1) printf("將第%2d 個圓盤從塔%2d 搬到塔%2d \n",n,s,d);
    else{
        Hanoi(n-1,s,d,m);
        printf("將第%2d 個圓盤從塔%2d 搬到塔%2d \n",n,s,d);
        Hanoi(n-1,m,s,d);
    }

}
int main(void){
    int n;
    printf("有多少圓盤要搬: ");
    scanf("%d", &n);
    Hanoi(n,1,2,3);
    system ("pause");return(0);
}
    