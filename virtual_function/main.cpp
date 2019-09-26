#include <iostream>
#include "AbstractCircle.h"
#include "ConcreteCircle.h"
#include "HollowCircle.h"

int main(){
    ConcreteCircle concrete;
    concrete.radius(10.0);
    concrete.render();

    HollowCircle hollow;
    hollow.radius(20.0);
    hollow.render();
}