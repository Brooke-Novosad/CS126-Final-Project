//
// Created by pokey on 4/19/2021.
//
#include <iostream>
#include "game_board.h"

int main() {
    size_t num = 3;
    slidepuzzle::GameBoard game(num);
    std::cout << game.GetNum();
    return 0;
}
