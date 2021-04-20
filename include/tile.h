//
// Created by pokey on 4/17/2021.
//

#ifndef FINAL_PROJECT_TILE_H
#define FINAL_PROJECT_TILE_H
#include "cinder/gl/gl.h"

using glm::vec2;

namespace slidepuzzle {

class Tile {
public:
    Tile(size_t num);

    Tile(bool set_emtpy);

    bool IsEmpty();

    size_t GetTileNum();

    void DrawTile(const vec2& top_point, size_t tile_width) const;

private:
    size_t tile_num_;
    bool empty_;

};
}
#endif //FINAL_PROJECT_TILE_H