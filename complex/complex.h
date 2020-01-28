#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#define PI = 3.1415926
using namespace std;
// 這是Complex計算機
class Complex
{
    // the function will return the reference
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);
    friend void sqrt(const Complex &, Complex &, Complex &);
    friend Complex operator-(const Complex &obj)
    {
        return Complex(-obj.real, -obj.imag);
    }

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i){};

    Complex setValue(double x, double y)
    {
        real = x;
        imag = y;
        return *this;
    }
    Complex operator+(const Complex &obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }
    Complex operator+(double x)
    {
        return Complex(real + x, imag);
    }
    Complex operator-(const Complex &obj)
    {
        return Complex(real - obj.real, imag - obj.imag);
    }
    Complex operator-(double x)
    {
        return Complex(real - x, imag);
    }
    Complex operator*(const Complex &obj)
    {
        double a = real * obj.real - imag * obj.imag;
        double b = real * obj.imag + imag * obj.real;
        return Complex(a, b);
    }
    Complex operator*(double x)
    {
        return Complex(real * x, imag * x);
    }
    Complex operator/(const Complex &);
    Complex operator/(double x)
    {
        return Complex(real / x, real / x);
    }
    Complex &operator=(const Complex &obj)
    {
        real = obj.real;
        imag = obj.imag;
        return *this; //get value
    }

private:
    double real, imag;
};

Complex Complex::operator/(const Complex &obj)
{
    try
    {
        if (obj.real == 0 && obj.imag == 0)
        {
            throw "ERROR!, Division by zero";
            exit(EXIT_FAILURE);
        }
    }
    catch (const char *err)
    {
        cerr << err << endl;
    }
    double a = (real * obj.real + imag * obj.imag) / (pow(obj.real, 2) + pow(obj.imag, 2));
    double b = (imag * obj.real - real * obj.imag) / (pow(obj.real, 2) + pow(obj.imag, 2));
    return Complex(a, b);
}

ostream &operator<<(ostream &output, const Complex &obj)
{
    if (obj.imag >= 0)
        output << setprecision(5) << obj.real << "+" << setprecision(5) << obj.imag << "i";
    else
        output << setprecision(5) << obj.real << "-" << setprecision(5) << -obj.imag << "i";
    return output;
}

istream &operator>>(istream &input, Complex &obj)
{
    string x;
    string real;
    string imag;
    input >> x;
    string::iterator it, it_1;
    try
    {
        for (it = x.begin(); it != x.end(); ++it)
        {
            if ((*it == '+' || *it == '-') && it != x.begin())
            {
                for (it_1 = x.begin(); it_1 != x.end(); ++it_1)
                    real.push_back(*it_1);
                for (it_1 = it; it_1 != x.end() - 1; ++it_1)
                {
                    imag.push_back(*it_1);
                    if (it_1 == it && it_1 == x.end() - 2)
                        imag.push_back('1');
                }
                obj.real = stod(real);
                obj.imag = stod(imag);
                return input;
            }
        }

        if (*(x.end() - 1) == 'i')
        {
            for (it = x.begin(); it != x.end() - 1; ++it)
            {
                imag.push_back(*it);
            }
            if (((*x.begin() == '-' || *x.begin() == '+') && (x.begin() == x.end() - 2)) || x.begin() == x.end() - 1)
                imag.push_back('1');
            obj.real = 0;
            obj.imag = stod(imag);
            return input;
        }

        else
        {
            for (it = x.begin(); it != x.end(); ++it)
                real.push_back(*it);
            obj.real = stod(real);
            obj.imag = 0;
            return input;
        }
    }
    catch (...)
    {
        cerr << "Wrong input Format." << endl;
        exit(EXIT_FAILURE);
    }
}

void sqrt(const Complex &x, Complex &out_1, Complex &out_2)
{
    double real = x.real, imag = x.imag;
    double r, theta;
    r = sqrt(pow(real, 2) + pow(imag, 2));
    theta = atan2(imag, real);
    out_1.setValue(sqrt(r) * cos(theta / 2), sqrt(r) * sin(theta / 2));
    out_2.setValue(sqrt(r) * cos(theta / 2 + 3.1415926), sqrt(r) * sin(theta / 2 + 3.1415926));
}

#endif