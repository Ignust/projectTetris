#ifndef OBJECTPOINT_HPP
#define OBJECTPOINT_HPP

#include "IObject.hpp"

class ObjectPoint: public IObject
{
public:
    ObjectPoint() {}
    virtual ~ObjectPoint() {}

    virtual void rotate() {}
    virtual void goDown() {}
    virtual void goLeft() {}
    virtual void goRight(){}

private:

};

#endif // OBJECTPOINT_HPP
