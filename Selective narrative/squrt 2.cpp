#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iNum, iSave, iPower = 0;
    int flag = 1;       /*=1 ��ܥi�Q2�㰣*/
    printf("please enter a number:");
    scanf("%d", &iNum);
    iSave = iNum;       /*�O�d��J*/
    while (flag && iNum != 1){
        if(iNum%2 == 0){
            iNum = iNum/2;
            iPower ++;
        }
        else flag = 0;
    }
    if(flag) printf("%d�O2��%d����\n",iSave,iPower);
    else  printf("%d���O2������\n",iSave);
    system("pause");
    return 0;
}