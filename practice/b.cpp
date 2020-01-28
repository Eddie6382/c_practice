#include <iostream>
#include <string>
using namespace std;

ostream &operator<<(ostream &os, const string &a)
{
    os << a;
    return os;
}

int main()
{
    cout << "yes" << endl;

    string a = "stan";
    cout << "svfv";
    return 0;
}