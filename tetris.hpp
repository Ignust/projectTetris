#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "Tetris/hmiFu.hpp"
#include "Tetris/manager.hpp"
#include "Tetris/manager_hmi_types.hpp"

class Tetris{
public:
    Tetris() {}
    ~Tetris() {}

    void run() {}

private:
    HmiFu mHmiFu;
    Manager mManager;
};

#endif // TETRIS_HPP
