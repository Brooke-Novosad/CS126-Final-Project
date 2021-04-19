//
// Created by pokey on 4/17/2021.
//

#ifndef FINAL_PROJECT_TILE_H
#define FINAL_PROJECT_TILE_H

#endif //FINAL_PROJECT_TILE_H

namespace slidepuzzle {

class Tile {
public:
    Tile(size_t num);

    Tile(bool set_emtpy);

    bool IsEmpty();

    size_t GetTileNum();

private:
    size_t tile_num_;
    bool empty_;

};
}