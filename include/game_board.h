//
// Created by pokey on 4/19/2021.
//
#pragma once
#include "cinder/gl/gl.h"
#include "tile.h"
#include <vector>
#include <algorithm>
#include <string>

using glm::vec2;

namespace slidepuzzle {

class GameBoard {
    public:
    GameBoard(size_t board_size);

    std::string GetNum();

    const std::vector<std::vector<Tile>>& GetTileVector();

    const std::vector<std::vector<vec2>>& GetPointsVector();

    void Display() const;

    private:

    void AddToTileVector();

    size_t board_size_;
    std::vector<std::vector<Tile>> tiles_;
    size_t tile_width_;
    std::vector<std::vector<vec2>> tile_points_;

    const vec2 kTop_corner = vec2(50, 50);
    const vec2 kBottom_corner = vec2(800, 800);
};
}