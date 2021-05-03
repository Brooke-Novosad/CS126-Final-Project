//
// Created by pokey on 4/19/2021.
//
#include "game_board.h"
#include <iostream>

//this class will be used to keep track of the board state, ie the order of numbers, the tiles and the open space.
// this will be used in the app so the key functions will be in here too.
// call in the puzzle game functions for the game to be played ie. if someone wins?
//i might not need that class and i could do it all in here

//need display like in gas container that displays the tiles

namespace slidepuzzle {

    GameBoard::GameBoard(size_t board_size, bool hard_mode) {
        board_size_ = board_size;
        hard_mode_ = hard_mode;
        size_t num = 0;
        curr_tile_ = Tile(true);
        tiles_.resize(board_size_, std::vector<Tile>(board_size_, Tile(num)));
        tile_points_.resize(board_size, std::vector<vec2>(board_size, vec2(0, 0)));
        AddToPointVector();
        AddToTileVector();
        curr_tile_coords_ = tile_points_[board_size_ - 1][board_size_ - 1];
    }

    GameBoard::GameBoard(std::vector<std::vector<size_t>> set_tiles, bool hard_mode) {
        size_t num = 0;
        hard_mode_ = hard_mode;
        curr_tile_ = Tile(true);
        board_size_ = set_tiles.size();
        tiles_.resize(board_size_, std::vector<Tile>(board_size_, Tile(num)));
        tile_points_.resize(board_size_, std::vector<vec2>(board_size_, vec2(0, 0)));
        AddToPointVector();
        size_t count = 0;
        for (size_t row = 0; row < board_size_; row++) {
            for (size_t col = 0; col < board_size_; col++) {
                if (row == board_size_ - 1 && col == board_size_ - 1) {
                    tiles_[row][col] = Tile(true);
                } else {
                    tiles_[row][col] = Tile(set_tiles[row][col]);
                }
                count++;
            }
        }
        curr_tile_coords_ = tile_points_[board_size_ - 1][board_size_ - 1];
    }

    void GameBoard::AddToPointVector() {
        tile_width_ = (size_t) (kBottom_corner.x - kTop_corner.x) / board_size_;
        vec2 curr_point = kTop_corner;
        for (size_t row = 0; row < board_size_; row++) {
            for (size_t col = 0; col < board_size_; col++) {
                tile_points_[row][col] = curr_point;
                if (col == board_size_ - 1) {
                    curr_point = vec2(kTop_corner.x, curr_point.y  + tile_width_);
                } else {
                    curr_point = vec2(curr_point.x + tile_width_, curr_point.y);
                }
            }
        }

    }

    void GameBoard::AddToTileVector() {
        std::vector<size_t> numbers;
        for (size_t num = 1; num < (board_size_ * board_size_); num++) {
            numbers.push_back(num);
        }
        std::shuffle(std::begin(numbers), std::end(numbers), std::random_device());
        size_t count = 0;
        for (size_t row = 0; row < board_size_; row++) {
            for (size_t col = 0; col < board_size_; col++) {
                if (row == board_size_ - 1 && col == board_size_ - 1) {
                    tiles_[row][col] = Tile(true);
                } else {
                    tiles_[row][col] = Tile(numbers.at(count));
                }
                count++;
            }
        }
    }

    const std::vector<std::vector<Tile>>& GameBoard::GetTileVector() {
        return tiles_;
    }

    const std::vector<std::vector<vec2>>& GameBoard::GetPointsVector() {
        return tile_points_;
    }

    Tile GameBoard::GetCurrTile() {
        return curr_tile_;
    }

    std::string GameBoard::GetNum() {
        std::string hi = std::to_string(tile_points_.at(1).at(0).x) + " " +
                         std::to_string(tile_points_.at(1).at(0).y);
        return hi;
    }

    void GameBoard::Display() const {
        for (size_t row = 0; row != tiles_.size(); row++) {
            for (size_t col = 0; col != tiles_.at(row).size(); col++) {
                tiles_[row][col].DrawTile(tile_points_[row][col], tile_width_);
            }
        }
        ci::gl::color(white);
        ci::gl::drawStrokedRect(ci::Rectf(kTop_corner, kBottom_corner));
        ci::gl::color(pink);
        ci::gl::drawStrokedRect(ci::Rectf(curr_tile_coords_, vec2(curr_tile_coords_.x + tile_width_,
                                                                  curr_tile_coords_.y + tile_width_)));
    }

    void GameBoard::ClickTile(const vec2& screen_coords) {
        for (size_t row = 0; row != tiles_.size(); row++) {
            for (size_t col = 0; col != tiles_.at(row).size(); col++) {
                vec2 point = tile_points_[row][col];
                if (point.x < screen_coords.x && point.x + tile_width_ > screen_coords.x && point.y < screen_coords.y &&
                    point.y + tile_width_ > screen_coords.y) {
                    curr_tile_ = tiles_[row][col];
                    curr_tile_coords_ = point;
                    curr_row = row;
                    curr_col = col;
                }
            }
        }
    }

    void GameBoard::SlideTile(direction direction) {
        if (!curr_tile_.IsEmpty()) {
            if (direction == up) {
                if (curr_row != 0) {
                    if (tiles_[curr_row - 1][curr_col].IsEmpty()) {
                        tiles_[curr_row - 1][curr_col] = curr_tile_;
                        tiles_[curr_row][curr_col] = Tile(true);
                    }
                }
            } else if (direction == down) {
                if (curr_row != board_size_ - 1) {
                    if (tiles_[curr_row + 1][curr_col].IsEmpty()) {
                        tiles_[curr_row + 1][curr_col] = curr_tile_;
                        tiles_[curr_row][curr_col] = Tile(true);
                    }
                }
            } else if (direction == left) {
                if (curr_col != 0) {
                    if (tiles_[curr_row][curr_col - 1].IsEmpty()) {
                        tiles_[curr_row][curr_col - 1] = curr_tile_;
                        tiles_[curr_row][curr_col] = Tile(true);
                    }
                }
            } else if (direction == right) {
                if (curr_col != board_size_ - 1) {
                    if (tiles_[curr_row][curr_col + 1].IsEmpty()) {
                        tiles_[curr_row][curr_col + 1] = curr_tile_;
                        tiles_[curr_row][curr_col] = Tile(true);
                    }
                }
            }
        }
    }

    bool GameBoard::IsGameWon() {
        if (hard_mode_) {
            if (!tiles_[board_size_ - 1][board_size_ - 1].IsEmpty()) {
                return false;
            }
        }
        std::vector<size_t> tile_nums;
        for (size_t row = 0; row != tiles_.size(); row++) {
            for (size_t col = 0; col != tiles_.at(row).size(); col++) {
                if (!tiles_[row][col].IsEmpty()) {
                    tile_nums.push_back(tiles_[row][col].GetTileNum());
                }
            }
        }
        for (size_t i = 0; i != tile_nums.size() - 1; i++) {
            if (tile_nums.at(i) + 1 != tile_nums.at(i + 1)) {
                return false;
            }
        }
        return true;
    }
}
