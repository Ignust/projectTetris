#include <stdio.h>
#include <termios.h>    //struct termios
#include <unistd.h>     //STDIN_FILENO
#include<cstdint>       //uint8_t
#include<iostream>


#include "Keyboard.hpp"


//-----------------------------------------------------------------------------
Keyboard::Keyboard()
    : mTimer()
//-----------------------------------------------------------------------------
{
    setKeypress();
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
    fd_set rfds;
    struct timeval tv;
    int32_t retval;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    tv.tv_sec = 0;
    tv.tv_usec = 0;
    retval = select(2, &rfds, NULL, NULL, &tv);
    if (retval)
    {
        //printf("Data is available now.\n");
        return getc(stdin);
    }
    else
    {
        //printf("No data available.\n");
        return 0;
    }
}

//-----------------------------------------------------------------------------
void Keyboard::setKeypress()
//-----------------------------------------------------------------------------
{
    static struct termios stored_settings;
    struct termios new_settings;

    tcgetattr(0,&stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0,TCSANOW,&new_settings);
}


