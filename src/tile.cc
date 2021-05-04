//
// Created by pokey on 4/17/2021.
//
#include "tile.h"

using glm::vec2;

namespace slidepuzzle {

    Tile::Tile(size_t num) {
        tile_num_ = num;
        empty_ = false;
    }

    Tile::Tile(bool set_emtpy) {
        tile_num_ = tile_empty_num;
        empty_ = set_emtpy;
    }

    size_t Tile::GetTileNum() {
        return tile_num_;
    }

    bool Tile::IsEmpty() {
        return empty_;
    }

    void Tile::DrawTile(const vec2& top_point, size_t tile_width) const {
        if (!empty_) {
            ci::gl::color(teal);
            ci::gl::drawSolidRect(ci::Rectf(top_point, vec2(top_point.x + tile_width,
                                                                  top_point.y + tile_width)));
            ci::gl::color(yellow);
            ci::gl::drawStrokedRect(ci::Rectf(top_point, vec2(top_point.x + tile_width,
                                                                      top_point.y + tile_width)));
            vec2 text = vec2(top_point.x + tile_width / 2, top_point.y + tile_width / 2);
            ci::gl::drawStringCentered(std::to_string(tile_num_),glm::vec2(top_point.x + tile_width / 2,
                                                                                   top_point.y + tile_width / 2),
                                                                      white, ci::Font(font, font_size));
        }
    }

}


