#ifndef FIELD_HPP
#define FIELD_HPP

#include"stdint.h"



class Field{
public:
    Field();
    ~Field();
    void showField();
    void SetChar(const uint8_t x, const uint8_t y, const uint8_t c);
    uint8_t GetChar(const uint8_t x, const uint8_t y);

private:
    void createField();
    void initField();
    void printGameField();
    void printStatusField();
    void printScoreField();
    void printRectangleBoudary(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t y2);
    void initGameField();
    void printLine(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2);



private:
    uint8_t** mFildArray;

};

#endif // FIELD_HPP
