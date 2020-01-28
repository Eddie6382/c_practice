#include <iostream>
#include <string>
#include "List.h"
using namespace std;

void instructions()
{
    cout << "Enter one of the following commands:\n"
         << " 1 to insert at beginning of the list\n"
         << " 2 to insert at end of the list\n"
         << " 3 to delete from beginning of the list\n"
         << " 4 to delete from end of the list\n"
         << " 5 to end kist processing\n";
}

template <typename T>
void testList(List<T> &listObject, const string &typeName)
{
    cout << "Teating a list of " << typeName << " values\n";
    instructions(); //displayu instructions

    int choice;
    T value; // store input value

    do
    {
        cout << " ? ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter" << typeName << " : ";
            cin >> value;
            listObject.insertFront(value);
            listObject.print();
            break;
        case 2:
            cout << "Enter" << typeName << " : ";
            cin >> value;
            listObject.insertBack(value);
            listObject.print();
            break;
        case 3:
            if (listObject.removeFront(value))
                cout << value << " remove from list\n";
            listObject.print();
            break;
        case 4:
            if (listObject.removeBack(value))
                cout << value << " remove from list\n";
            listObject.print();
            break;
        }
    } while (choice < 5);

    cout << "End list  testy\n\n";
}

int main()
{
    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");
}