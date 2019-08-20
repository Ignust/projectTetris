#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "tetrisElements/Engine.hpp"
#include "tetrisElements/Field.hpp"
#include "tetrisElements/Keyboard.hpp"
#include "tetrisElements/IObject.hpp"
#include "stdint.h"


class Manager{
public:
    Manager();
    ~Manager();

    bool checkUserAction();
    void showField();
private:
    Engine mEngine;
    Field mField;
    Keyboard mKeyboard;
    IObject *mObjCurr;
    IObject *mObjNext;
};

#endif // MANAGER_HPP
