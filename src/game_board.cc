//
// Created by pokey on 4/19/2021.
//
#include "game_board.h"

//this class will be used to keep track of the board state, ie the order of numbers, the tiles and the open space.
// this will be used in the app so the key functions will be in here too.
// call in the puzzle game functions for the game to be played ie. if someone wins?
//i might not need that class and i could do it all in here

//need display like in gas container that displays the tiles

namespace slidepuzzle {

    GameBoard::GameBoard(size_t board_size) {
        board_size_ = board_size;
        size_t num = 0;
        tiles_.resize(board_size_, std::vector<Tile>(board_size_, Tile(num)));
        std::vector<size_t> numbers;
        for (size_t num = 1; num < (board_size * board_size); num++) {
            numbers.push_back(num);
        }
        std::random_shuffle(numbers.begin(), numbers.end());
        size_t count = 0;
        for (size_t row = 0; row < board_size; row++) {
            for (size_t col = 0; col < board_size; col++) {
                if (row == board_size - 1 && col == board_size - 1) {
                    tiles_[row][col] = Tile(true);
                } else {
                    tiles_[row][col] = Tile(numbers.at(count));
                }
                count++;
            }
        }
    }

    std::string GameBoard::GetNum() {
        std::string hi;
        for (size_t row = 0; row < board_size_; row++) {
            for (size_t col = 0; col < board_size_; col++) {
                hi = hi + std::to_string(tiles_[row][col].GetTileNum());
            }
        }
        return hi;
    }

}
