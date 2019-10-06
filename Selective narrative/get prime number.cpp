#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int P,x;
    int factor = 0;               /*璸衡碭计*/
    printf("块2计:");scanf("%d",&P);

    for(x=2; x*x<P; x++){          /*xΤǎ耞琌ぃ琌计*/
        if(!(P%x)){
            if(factor==0) printf("计Τ:  %d %d",x,P/x );
            else printf( "  %d %d",x, P/x);
            factor += 2;
        }
    }
    if(x*x == P){           /*秆∕キよ拜肈*/
        if(factor==0) printf("计Τ:  %d",x );
        else printf( "  %d",x);
        factor += 1;
    }

    if(factor==0)printf("%d琌借计\n",P);
    else printf("\nΤ%d计 \n",factor);

    system("pause");
    return 0;
}