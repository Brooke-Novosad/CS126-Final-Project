//
// Created by pokey on 4/17/2021.
//
#include <catch2/catch.hpp>
#include "game_board.h"
#include <iostream>

TEST_CASE("") {
    size_t num = 3;
    slidepuzzle::GameBoard game(num);
    std::cout << game.GetNum();
}
