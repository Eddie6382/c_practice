#ifndef ABSTRACTCIRCLE
#define ABSTRACTCIRCLE

class AbstractCircle
{
public:
    void radius(double radius){
        _radius = radius;
    }
    double radius(){
        return _radius;
    }
    virtual void render() = 0; //pure virtual 
protected:
    double _radius;
};

#endif
