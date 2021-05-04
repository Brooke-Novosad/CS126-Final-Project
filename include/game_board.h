//
// Created by pokey on 4/19/2021.
//
#pragma once
#include "cinder/gl/gl.h"
#include "tile.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <chrono>

using glm::vec2;

namespace slidepuzzle {
/**
* The class that is in charge of drawing the board and setting up the order of tiles.
*/
    class GameBoard {
    public:
        // enums for the direction the tile slides in
        enum direction { up, down, left, right };

        /**
         * Constructor that sets the board size and initializes the vectors of the tiles in a random order.
         * @param board_size the number of tiles in a row
         */
        GameBoard(size_t board_size, bool hard_mode);

        /**
         * Constructor that makes a 2D vector of tiles with the numbers in the passed vector. Bottom left corner will
         * always be the empty tile.
         * @param set_tiles a 2D vector of numbers for tiles
         */
        GameBoard(std::vector<std::vector<size_t>> set_tiles, bool hard_mode);

        /**
         * Gets the vector of all the tiles for this game.
         * @return a vector of Tiles
         */
        const std::vector<std::vector<Tile>>& GetTileVector();

        /**
         * Gets the vector of the top left positions for each tile.
         * @return a vector of points
         */
        const std::vector<std::vector<vec2>>& GetPointsVector();

        /**
         * Gets the current tile that the player clicked on.
         * @return a Tile that is the current tile
         */
        Tile GetCurrTile();

        /**
         * Displays the board and the current positions of the Tiles.
         */
        void Display() const;

        /**
         * Sets the current tile that the player wants to move.
         * @param screen_coords the screen coordinates at which the player clicked
         */
        void ClickTile(const vec2& screen_coords);

        /**
         * Moves the current tile in the direction that the player clicked.
         * @param direction the direction that the player clicked
         */
        void SlideTile(direction direction);

        /**
         * Checked if the player won for that move.
         * @return a boolean of if they won
         */
        bool IsGameWon();

    private:
        /**
         * A helper method for the constructor that adds Tiles to it's vector.
         */
        void AddToTileVector();

        /**
         * A helper method for the constructors that adds coordinates to it's vector.
         */
        void AddToPointVector();

        size_t board_size_;
        size_t tile_width_;
        bool hard_mode_;

        std::vector<std::vector<Tile>> tiles_;
        std::vector<std::vector<vec2>> tile_points_;

        Tile curr_tile_ = Tile(true);
        vec2 curr_tile_coords_;
        size_t curr_row;
        size_t curr_col;

        vec2 kTop_corner = vec2(50, 50);
        vec2 kBottom_corner = vec2(800, 800);
        ci::Color white = "white";
        ci::Color pink = "pink";
    };
}
