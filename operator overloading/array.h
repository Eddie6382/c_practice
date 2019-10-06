#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Array
{
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);

public:
    Array(int = 10);
    Array(const Array &);
    ~Array();
    int getSize() const; //the function can not change member variables

    const Array &operator=(const Array &);
    bool operator==(const Array &) const;

    bool operator!=(const Array &right) const
    {
        return !(*this == right);
    }
    int &operator[](int);
    int operator[](int) const;

private:
    int size;
    int *ptr;
};

Array::Array(int arraySize)
{
    size = arraySize > 0 ? arraySize : 10;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = 0;
} //default constructor

Array::Array(const Array &ArrayToCopy) : size(ArrayToCopy.size)
{
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = ArrayToCopy.ptr[i];
}
/*
Array copy constructor, must receive its arg by reference, or the program will result in infinite recursion
The arg to a copy constructor must be a const reference to allow a const object to copy
*/

Array::~Array()
{
    delete[] ptr;
}

int Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];
    }
    return *this;
} //array is a type

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
        return false;
    for (int i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}

//reference return creates a modifiable lvalue(for non-const arrays)
int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >> size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range" << endl;
        exit(1); //terminate the program
    }
    return ptr[subscript]; //reference return
}

//const reference return creates a rvalue
int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >> size)
    {
        cerr << "\nError: Subscript " << subscript << " out of range" << endl;
        exit(1); //terminate the program
    }
    return ptr[subscript]; //returns copy of this element
}

istream &operator>>(istream &input, Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        input >> a.ptr[i];
    }
    return input;
}

ostream &operator<<(ostream &output, const Array &a)
{
    int i;

    //output private ptr-based array
    for (int i = 0; i < a.size; i++)
    {
        output << setw(12) << a.ptr[i];
        if ((i + 1) % 4 == 0)
            output << endl;
    }
    if (i % 4 != 0)
        output << endl;
    return output;
}
#endif
