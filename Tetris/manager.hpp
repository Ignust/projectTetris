#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "tetrisElements/Engine.hpp"
#include "tetrisElements/Field.hpp"
#include "tetrisElements/Keyboard.hpp"
#include "tetrisElements/IObject.hpp"

class Manager{
public:
    Manager();
    ~Manager();

    bool checkUserAction();
private:
    Engine mEngine;
    Field mField;
    Keyboard mKeyboard;
    IObject *mObjCurr;
    IObject *mObjNext;
};

#endif // MANAGER_HPP
