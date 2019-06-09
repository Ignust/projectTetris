#ifndef IOBJECT_HPP
#define IOBJECT_HPP


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

};

#endif // IOBJECT_HPP
