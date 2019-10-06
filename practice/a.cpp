#include <string>
#include <iostream>
using namespace std;

int main()
{
    char a[10] = "abcdefgh";
    char *p_a = a;
    char *p_b = a + 7;
    char *p_c = a + 4;
    cout << *p_a << *p_c << *p_b << endl;
    cout << (p_c > a && p_c < p_b) << endl;
    p_b -= 2;
    cout << *(p_a) << *p_c << *p_b << endl;

    char c = 'a';
    char d = 'f';
    char f = 16;
    char e[10] = "123456";
    cout << e << '\b' << f << char(16) << ' ' << endl;
    cout << f;
    cout << (1 << 8) << endl;
}