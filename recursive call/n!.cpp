#include<stdio.h>
#include<stdlib.h>
long factor(long);
long factor(long n){
    long ret;
    if(n==1) return(1);
    ret = n*factor(n-1);
    return(ret);
}
int main(void){
    int n;
    printf("��J�Q�n�����hn: ");
    scanf("%d", &n);
    printf("%2d! = %d\n",n,factor(n));
    system ("pause");return(0);
}
    