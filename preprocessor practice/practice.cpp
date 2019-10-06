#include<stdio.h>
#include<stdlib.h>
#include "area.h"
int main(void)
{
    float l, h, r;
    printf("��Υb�|��: "); scanf("%f", &r);
    printf("��Ϊ����n: %1.2f\n",circle(r));
    printf("����Ϊ����P�e: "); scanf("%f %f", &l,&h);
    printf("��Ϊ����n��: %1.2f\n", rectangle(l,h));
    system ("pause"); return(0);

}