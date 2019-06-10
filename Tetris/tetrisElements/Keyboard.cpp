#include <stdio.h>
#include <termios.h>    //struct termios
#include <unistd.h>     //STDIN_FILENO
#include<cstdint>       //uint8_t


#include "Keyboard.hpp"


//-----------------------------------------------------------------------------
Keyboard::Keyboard()
    : mTimer()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
Keyboard::~Keyboard()
//-----------------------------------------------------------------------------
{

}

//-----------------------------------------------------------------------------
bool Keyboard::checkButtons()
//-----------------------------------------------------------------------------
{
    struct termios oldt;
    struct termios newt;
    uint8_t button;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    button = static_cast<uint8_t>(getchar());
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    printf("Button %d = %c was pressed\n", button, static_cast<char>(button));

    return false;
}
