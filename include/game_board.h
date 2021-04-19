//
// Created by pokey on 4/19/2021.
//

#ifndef FINAL_PROJECT_GAME_BOARD_H
#define FINAL_PROJECT_GAME_BOARD_H

#endif //FINAL_PROJECT_GAME_BOARD_H
#include "tile.h"
#include <vector>
#include <algorithm>
#include <string>

namespace slidepuzzle {

class GameBoard {
    public:
    GameBoard(size_t board_size);

    std::string GetNum();

    private:
    size_t board_size_;
    std::vector<std::vector<Tile>> tiles_;
};
}