#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hello World\n");
    int i;
    float fnum[12], fnum_min, fnum_max;
    srand((unsigned)time(NULL));
    for(i=0;i<12;i++){
        fnum[i] = 100.0f*(float)rand()/RAND_MAX;
        printf("%5.2f  ",fnum[i]);
        if((i+1)%3==0) printf("\n");
    }
    fnum_min = 101; 
    fnum_max = -1;
    for(i=0;i<12;i++){
        if(fnum[i]<fnum_min) fnum_min = fnum[i];
        if(fnum[i]>fnum_max) fnum_max = fnum[i];
    }
    printf("The biggest number is %5.2f\nThe smallest number is %5.2f\n",fnum_max, fnum_min);
    system("pause");
    return 0;
}
