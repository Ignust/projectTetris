#include"Field.hpp"
#include "../manager_hmi_types.hpp"
#include <iostream>


using namespace std;



//-----------------------------------------------------------------------------
Field::Field()
    : mFildArray(nullptr)
//-----------------------------------------------------------------------------
{
    createField();
    initField();

}

//-----------------------------------------------------------------------------
Field::~Field()
//-----------------------------------------------------------------------------
{
    for(int a = 0; a < Y_SIZE; ++a){
        delete [] mFildArray[a];
    }
    delete [] mFildArray;
}

//-----------------------------------------------------------------------------
void Field::showField()
//-----------------------------------------------------------------------------
{
    for(int a = 0; a < Y_SIZE; ++a){
        for(int b = 0; b < X_SIZE; ++b){
            cout << mFildArray[a][b];
        }
        cout << endl;
    }
}

//-----------------------------------------------------------------------------
void Field::SetChar(const uint8_t x, const uint8_t y, const uint8_t c)
//-----------------------------------------------------------------------------
{
    //mFildArray[y][x] = c;
    for(int a = 0; a < Y_SIZE; ++a){
        for(int b = 0; b < X_SIZE; ++b){
            if (a == y && b == x){
                mFildArray[a][b] = c;
            }

        }
    }
}

//-----------------------------------------------------------------------------
uint8_t Field::GetChar(const uint8_t x, const uint8_t y)
//-----------------------------------------------------------------------------
{
    return mFildArray[y][x];
}

//-----------------------------------------------------------------------------
void Field::createField()
//-----------------------------------------------------------------------------
{
    mFildArray = new uint8_t*[Y_SIZE];
    for(int a = 0; a < Y_SIZE; ++a){
        mFildArray[a] = new uint8_t[X_SIZE];
    }

    for(int y = 0; y < Y_SIZE; ++y){
        for(int x = 0; x < X_SIZE; ++x){
            mFildArray[y][x] = ' ';
        }
    }
}

//-----------------------------------------------------------------------------
void Field::initField()
//-----------------------------------------------------------------------------
{
    printGameField();
    printStatusField();
    printScoreField();
    /*
    for(int y = 0; y < GAME_FIELD_Y_SIZE; ++y){
        for(int x = 0; x < GAME_FIELD_X_SIZE; ++x){
            mFildArray[y][x] = '0';
        }
    }*/
}

//-----------------------------------------------------------------------------
void Field::printGameField()
//-----------------------------------------------------------------------------
{
    printRectangleBoudary(GAME_FIELD_X_START, GAME_FIELD_Y_START, GAME_FIELD_X_FINISH, GAME_FIELD_Y_FINISH);
    initGameField();
}

//-----------------------------------------------------------------------------
void Field::printStatusField()
//-----------------------------------------------------------------------------
{
    printRectangleBoudary(STATUS_FIELD_X_START, STATUS_FIELD_Y_START, STATUS_FIELD_X_FINISH, STATUS_FIELD_Y_FINISH);
}

//-----------------------------------------------------------------------------
void Field::printScoreField()
//-----------------------------------------------------------------------------
{
    printRectangleBoudary(SCORE_FIELD_X_START, SCORE_FIELD_Y_START, SCORE_FIELD_X_FINISH, SCORE_FIELD_Y_FINISH);
        //printScoreTitle(L">Score:");
        //printScore();
}

//-----------------------------------------------------------------------------
void Field::printRectangleBoudary(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2)
//-----------------------------------------------------------------------------
{
    printLine(x1 - 1, y1 - 1, x2 + 1 , y1 - 1);
    printLine(x1 - 1, y2 + 1, x2 + 1 , y2 + 1);
    printLine(x1 - 1, y1 - 1, x1 - 1, y2 + 1);
    printLine(x2 + 1, y1 - 1, x2 + 1, y2 + 1);
}

//-----------------------------------------------------------------------------
void Field::initGameField()
//-----------------------------------------------------------------------------
{
    for (uint8_t y = GAME_FIELD_Y_START; y <= GAME_FIELD_Y_SIZE; ++y) {
            for (uint8_t x = GAME_FIELD_X_START; x <= GAME_FIELD_X_SIZE; ++x) {
                SetChar(x,y, SPACE_SYMBOL);
            }
        }
}
//-----------------------------------------------------------------------------
void Field::printLine(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2)
//-----------------------------------------------------------------------------
{
    if (x1 == x2) {
            for (uint8_t i = y1; i <= y2; ++i) {
                SetChar(x1, i, BOUNDARY_SYMBOL);
            }
        }
        else if (y1 == y2) {
            for (uint8_t i = x1; i <= x2; ++i) {
                SetChar(i, y1, BOUNDARY_SYMBOL);
            }
        }
}

