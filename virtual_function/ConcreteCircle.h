#ifndef CONCRETECIRCLE
#define CONCRETECIRCLE
#include "AbstractCircle.h"
#include <iostream>
using namespace std;

class ConcreteCircle : public AbstractCircle{
public:
    void render(){
        cout << "draw a concrete circle with radius = " << _radius << endl;
    }
};

#endif