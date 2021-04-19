//
// Created by pokey on 4/17/2021.
//
#include "tile.h"

namespace slidepuzzle {

    Tile::Tile(size_t num) {
        tile_num_ = num;
        empty_ = false;
    }

    Tile::Tile(bool set_emtpy) {
        empty_ = set_emtpy;
    }

    size_t Tile::GetTileNum() {
        return tile_num_;
    }

    bool Tile::IsEmpty() {
        return empty_;
    }

}
