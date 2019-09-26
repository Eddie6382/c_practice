#ifndef HOLLOWCIRCLE
#define HOLLOWCIRCLE
#include "AbstractCircle.h"
#include <iostream>
using namespace std;

class HollowCircle : public AbstractCircle {
public:
    void render(){
        cout << "draw a hollow circle with radius = " << _radius << endl;
    }
};

#endif