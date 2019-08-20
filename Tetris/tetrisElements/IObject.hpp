#ifndef IOBJECT_HPP
#define IOBJECT_HPP
#include "stdint.h"

class IObject
{
public:
    IObject() {}
    virtual ~IObject() {}

    virtual void rotate() = 0;
    virtual void goDown() = 0;
    virtual void goLeft() = 0;
    virtual void goRight() = 0;

private:
    uint8_t Xpos;
    uint8_t Ypos;

};

#endif // IOBJECT_HPP
