#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int P,x;
    int factor = 0;               /*�p��X�Ӧ]��*/
    printf("��J�@�Ӥj��2����:");scanf("%d",&P);

    for(x=2; x*x<P; x++){          /*x���p���j�P�_�O���O�]��*/
        if(!(P%x)){
            if(factor==0) printf("�]�Ʀ�:  %d %d",x,P/x );
            else printf( "  %d %d",x, P/x);
            factor += 2;
        }
    }
    if(x*x == P){           /*�ѨM���誺���D*/
        if(factor==0) printf("�]�Ʀ�:  %d",x );
        else printf( "  %d",x);
        factor += 1;
    }

    if(factor==0)printf("%d�O���\n",P);
    else printf("\n�@��%d�Ӧ]�� \n",factor);

    system("pause");
    return 0;
}