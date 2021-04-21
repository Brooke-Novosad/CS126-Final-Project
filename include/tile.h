//
// Created by pokey on 4/17/2021.
//

#ifndef FINAL_PROJECT_TILE_H
#define FINAL_PROJECT_TILE_H
#include "cinder/gl/gl.h"

using glm::vec2;

namespace slidepuzzle {

/**
 *  Creates a tile with a number associated and if it is the empty tile.
 */
class Tile {
public:
    /**
     * Constructs a tile that has a number.
     * @param num the number associated with the tile
     */
    Tile(size_t num);

    /**
     * A constructor used for constructing the empty tile.
     * @param set_emtpy a boolean for if the tile is empty
     */
    Tile(bool set_emtpy);

    bool IsEmpty();

    size_t GetTileNum();

    /**
     * Draws a tile with the correct number.
     * @param top_point the top left coordinate of the tile
     * @param tile_width the width of the tile
     */
    void DrawTile(const vec2& top_point, size_t tile_width) const;

private:
    size_t tile_num_;
    bool empty_;

    size_t tile_empty_num = 1000;
    ci::Color teal = "teal";
    ci::Color yellow = "yellow";
    ci::Color white = "white";
    ci::Font tile_font = ci::Font("Arial", 50);
};
}
#endif //FINAL_PROJECT_TILE_H