#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Timer.hpp"

class Keyboard{
public:
    Keyboard();
    ~Keyboard();

    bool checkButtons();
private:
    Timer mTimer;
};

#endif // KEYBOARD_HPP
