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

//add an if in app that says if the game started or not for a menu
// actually use an enum to see what state of the game you are in
// make a menu class for menu logic
//menu has a class and the game has a class they both have display
// when a button is pressed it changes the boolean or enum in the app class
using glm::vec2;

namespace slidepuzzle {
/**
* The class that is in charge of drawing the board and setting up the order of tiles.
*/
    class GameBoard {
    public:
        /**
         * Constructor that sets the board size and initializes the vectors of the tiles in a random order.
         * @param board_size the number of tiles in a row
         */
        GameBoard(size_t board_size);

        /**
         * A method that helps print things out. This is for making sure things work, won't be included at the end.
         * @return a string
         */
        std::string GetNum();

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
         * Displays the board and the current positions of the Tiles.
         */
        void Display() const;

        /**
         * Sets the current tile that the player wants to move.
         * @param screen_coords the screen coordinates at which the player clicked
         */
        void ClickTile(const vec2& screen_coords);

        void SlideTile(std::string direction);

        bool IsGameWon();


    private:

        /**
         * A helper method for the constructor that adds Tiles and coordinates to their respective vectors.
         */
        void AddToTileVector();

        size_t board_size_;
        size_t tile_width_;

        std::vector<std::vector<Tile>> tiles_;
        std::vector<std::vector<vec2>> tile_points_;

        Tile curr_tile_ = Tile(true);
        vec2 curr_tile_coords_;
        size_t curr_row;
        size_t curr_col;

        const vec2 kTop_corner = vec2(50, 50);
        const vec2 kBottom_corner = vec2(800, 800);
        const ci::Color white = "white";
        const ci::Color pink = "pink";
        std::string up = "up";
        std::string down = "down";
        std::string left = "left";
        std::string right = "right";
    };
}
