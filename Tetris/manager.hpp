#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "tetrisElements/Engine.hpp"
#include "tetrisElements/Field.hpp"
#include "tetrisElements/Keyboard.hpp"
#include "tetrisElements/Object.hpp"

class Manager{
public:
    Manager() {}
    ~Manager() {}


private:
    Engine mEngine;
    Field mField;
    Keyboard mKeyboard;
    Object mObjCurr;
    Object mObjNext;
};

#endif // MANAGER_HPP
