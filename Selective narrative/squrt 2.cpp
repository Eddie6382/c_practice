#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iNum, iSave, iPower = 0;
    int flag = 1;       /*=1 表示可被2整除*/
    printf("please enter a number:");
    scanf("%d", &iNum);
    iSave = iNum;       /*保留輸入*/
    while (flag && iNum != 1){
        if(iNum%2 == 0){
            iNum = iNum/2;
            iPower ++;
        }
        else flag = 0;
    }
    if(flag) printf("%d是2的%d次方\n",iSave,iPower);
    else  printf("%d不是2的次方\n",iSave);
    system("pause");
    return 0;
}