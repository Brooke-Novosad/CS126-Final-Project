//
// Created by pokey on 4/17/2021.
//
#include <catch2/catch.hpp>
#include "game_board.h"
#include <iostream>

TEST_CASE("Constructor") {
    size_t num = 3;
    slidepuzzle::GameBoard game(num);
    SECTION("Tiles added correctly") {
        std::vector<std::vector<slidepuzzle::Tile>> test_tiles = game.GetTileVector();
        size_t num_empty = 0;
        size_t num_tiles = 0;
        for (size_t row = 0; row != test_tiles.size(); row++) {
            for (size_t col = 0; col != test_tiles.at(row).size(); col++) {
                num_tiles++;
                if (test_tiles[row][col].IsEmpty()) {
                    num_empty++;
                }
            }
        }
        REQUIRE(test_tiles.size() == 3);
        REQUIRE(num_tiles == 9);
        REQUIRE(num_empty == 1);
    }
    SECTION("Numbers on tiles all different") {
        std::vector<std::vector<slidepuzzle::Tile>> test_tiles = game.GetTileVector();
        std::vector<size_t> tile_nums;
        for (size_t row = 0; row != test_tiles.size(); row++) {
            for (size_t col = 0; col != test_tiles.at(row).size(); col++) {
                if (!test_tiles[row][col].IsEmpty()) {
                    tile_nums.push_back(test_tiles[row][col].GetTileNum());
                }
            }
        }
        bool two_num_same = false;
        for (size_t num = 0; num != tile_nums.size() - 1; num++) {
            for (size_t comp = num + 1; comp != tile_nums.size(); comp++) {
                if (tile_nums.at(num) == tile_nums.at(comp)) {
                    two_num_same = true;
                }
            }
        }
        REQUIRE(two_num_same == false);
    }
    SECTION("Square points added correctly") {
        std::vector<std::vector<vec2>> test_points = game.GetPointsVector();
        REQUIRE(test_points.at(0).size() == 3);
        REQUIRE(test_points.at(1).size() == 3);
        REQUIRE(test_points.at(2).size() == 3);
        REQUIRE(test_points[0][0] == vec2(50, 50));
        REQUIRE(test_points[1][0] == vec2(50, 300));
        REQUIRE(test_points[2][0] == vec2(50, 550));
        REQUIRE(test_points[2][2] == vec2(550, 550));
    }
    SECTION("Tile width is correct") {
        std::vector<std::vector<vec2>> test_points = game.GetPointsVector();
        REQUIRE(test_points[0][1].x - test_points[0][0].x == 250);
        REQUIRE(test_points[1][1].x - test_points[1][0].x == 250);
        REQUIRE(test_points[2][1].x - test_points[2][0].x == 250);
    }
    size_t num_big = 4;
    slidepuzzle::GameBoard game_big(num_big);
    SECTION("Tiles added with bigger board size") {
        std::vector<std::vector<slidepuzzle::Tile>> test_tiles = game_big.GetTileVector();
        size_t num_empty = 0;
        size_t num_tiles = 0;
        for (size_t row = 0; row != test_tiles.size(); row++) {
            for (size_t col = 0; col != test_tiles.at(row).size(); col++) {
                num_tiles++;
                if (test_tiles[row][col].IsEmpty()) {
                    num_empty++;
                }
            }
        }
        REQUIRE(test_tiles.size() == 4);
        REQUIRE(num_tiles == 16);
        REQUIRE(num_empty == 1);
    }
    SECTION("Square points with bigger size") {
        std::vector<std::vector<vec2>> test_points = game_big.GetPointsVector();
        REQUIRE(test_points.at(0).size() == 4);
        REQUIRE(test_points.at(1).size() == 4);
        REQUIRE(test_points.at(2).size() == 4);
        REQUIRE(test_points.at(3).size() == 4);
        REQUIRE(test_points[0][0] == vec2(50, 50));
        REQUIRE(test_points[1][0] == vec2(50, 237));
        REQUIRE(test_points[2][0] == vec2(50, 424));
        REQUIRE(test_points[3][0] == vec2(50, 611));
        REQUIRE(test_points[3][3] == vec2(611, 611));
    }
    SECTION("Tile width with bigger board size") {
        std::vector<std::vector<vec2>> test_points = game_big.GetPointsVector();
        REQUIRE(test_points[0][1].x - test_points[0][0].x == 187);
        REQUIRE(test_points[1][1].x - test_points[1][0].x == 187);
        REQUIRE(test_points[2][1].x - test_points[2][0].x == 187);
        REQUIRE(test_points[3][1].x - test_points[3][0].x == 187);
    }
}
