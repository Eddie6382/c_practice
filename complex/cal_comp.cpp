#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <set>
#include "complex.h"
using namespace std;

char enterChoice();

int main()
{
    Complex a;
    Complex b;
    cout << "please enter a complex (a+bi), no space: " << endl;
    cin >> a;

    char choice;
    while ((choice = enterChoice()) != 'q')
    {
        cout << "please enter another complex (a+bi), no space: " << endl;
        cin >> b;
        switch (choice)
        {
        case '+':
            a = a + b;
            cout << "the reault is:\n"
                 << a << endl;
            break;
        case '-':
            a = a - b;
            cout << "the reault is:\n"
                 << a << endl;
            break;
        case '*':
            a = a * b;
            cout << "the reault is:\n"
                 << a << endl;
            break;
        case '/':
            a = a / b;
            cout << "the reault is:\n"
                 << a << endl;
            break;
        case 'q':
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

char enterChoice()
{
    set<char> s = {'+', '-', '*', '/', 'q'};
    cout << "what do you want to do on the complex ( +, -, *, / ) or press ( q ) to quit: ";
    char menuChoice;
    cin >> menuChoice;
    try
    {
        if (!s.count(menuChoice))
            throw "Invalid command.";
        return menuChoice;
    }
    catch (const char *err)
    {
        cerr << err << endl;
        exit(EXIT_FAILURE);
    }
}