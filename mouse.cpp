#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#define X_MAX 10
#define Y_MAX 10

class CMouse
{
  private:
    int ix, iy;
    int iStatus;
    char cIcon;
    char *cMicon;

  public:
    CMouse(int x = 1, int y = 1, char cIcon = '@')
    { //CONSTRUCTOR
        ix = x;
        iy = y;
        iStatus = 1;
        cMicon = new char[2];
        cIcon = cMicon[0] = '@'; //cMicon[0] = *(cMicon+0)指標運算
        cMicon[1] = 'Q';
    }
    ~CMouse() { delete[] cMicon; }
    void SetPos(int x, int y)
    {
        ix = x;
        iy = y;
    }
    void SetIcon(char cN, char cB)
    {
        cIcon = cMicon[0] = cN;
        cMicon[1] = cB;
    }
    void Show();
    int Update(char cIn);
    int GetStatus() { return (iStatus); }
}; //class定義記得要加冒號

void CMouse::Show()
{
    system("cls");
    for (int i = 1; i <= ix; i++)
        cout << endl;
    cout << setw(iy + 1) << setfill(' ') << cIcon << endl;
}

int CMouse::Update(char cIn)
{
    switch (cIn)
    {
    case 'w':
        ix--; //往下
        if (ix < 0)
            iStatus = 0;
        else if (ix == 0)
        {
            iStatus = 2;
            cIcon = cMicon[1];
        }
        else if (iy >= 1 && iy <= Y_MAX)
        {
            iStatus = 1;
            cIcon = cMicon[0];
        }
        break;
    case 's':
        ix++;
        if (ix > X_MAX + 1)
            iStatus = 0;
        else if (ix == X_MAX + 1)
        {
            iStatus = 2;
            cIcon = cMicon[1];
        }
        else if (iy >= 1 && iy <= Y_MAX)
        {
            iStatus = 1;
            cIcon = cMicon[0];
        }
        break;
    case 'a':
        iy--;
        if (iy < 0)
            iStatus = 0;
        else if (iy == 0)
        {
            iStatus = 2;
            cIcon = cMicon[1];
        }
        else if (ix >= 1 && ix <= X_MAX)
        {
            iStatus = 1;
            cIcon = cMicon[0];
        }
        break;
    case 'd':
        iy++;
        if (iy > Y_MAX + 1)
            iStatus = 0;
        else if (iy == Y_MAX + 1)
        {
            iStatus = 2;
            cIcon = cMicon[1];
        }
        else if (ix >= 1 && ix <= X_MAX)
        {
            iStatus = 1;
            cIcon = cMicon[0];
        }
        break;
    }
    return (iStatus);
}
int main(void)
{
    char cIn;
    int iStatus;
    CMouse mouseX(1, 2);
    //mouseX.SetPos(5, 5);
    mouseX.SetIcon('$', '*');
    mouseX.Show();
    //iStatus = mouseX.iStatus;
    iStatus = mouseX.GetStatus();
    while (iStatus != 0)
    {
        cIn = getch();                //不會將字元輸出在螢幕上 也不用按enter鍵
        iStatus = mouseX.Update(cIn); //讓老鼠畫出自己的位置
        if (iStatus)
            mouseX.Show();
        else
            cout << "mouse is already dead, game over" << endl;
    }
    return (0);
}