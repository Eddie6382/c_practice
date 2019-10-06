#include <iostream>
using namespace std;

struct StuScores
{
    char cStuNames[10];
    int iChi;
    int iEng;
    int iMat;
    float Ave;
};
int main()
{
    struct StuScores stu[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("hahaha\n");
        cout << "enter your name: "; //哈哈哈
        cin.get(stu[i].cStuNames, 10);
        cout << "Chinese score: ";
        cin >> stu[i].iChi;
        cout << "English score: ";
        cin >> stu[i].iEng;
        cout << "Math score: ";
        cin >> stu[i].iMat;
        stu[i].Ave = (stu[i].iChi + stu[i].iEng + stu[i].iMat) / 3.0;
        cout << "average score: " << stu[i].Ave << endl;
        fflush(stdin);
    }
    for (i = 0; i < 3; i++)
    {
        cout << stu[i].cStuNames << " 's score: " << stu[i].Ave << endl;
    }
    return 0;
}
