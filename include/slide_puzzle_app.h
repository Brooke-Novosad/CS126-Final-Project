//
// Created by pokey on 4/17/2021.
//
#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_board.h"
#include "menu.h"

namespace slidepuzzle {

/**
* An app for visualising the slide puzzle game.
*/
    class SlidePuzzleApp : public ci::app::App {

    public:
        enum gameState {menu, playGame};
        /**
         * A constructor that sets up the app screen.
         */
        SlidePuzzleApp();

        /**
         * Draws the background, game board, and tiles.
         */
        void draw() override;

        /**
         * When mouse is clicked it will highlight the tile the player clicked on.
         * @param event the event the mouse pad is detecting
         */
        void mouseDown(ci::app::MouseEvent event) override;

        /**
         * When a key on the keyboard is clicked, it will trigger the game board to do something.
         * @param event the event of the key that is pressed
         */
        void keyDown(ci::app::KeyEvent event) override;

        void Create();

        const int kWindowSize = 875;
        const int kMargin = 500;

    private:
        Menu game_menu_ = Menu();
        gameState curr_game_state_;
        std::string font = "Arial";
        float font_size = 100;
        size_t board_size_ = 3;
        bool hard_mode_ = false;
        // For showing win screen
        std::vector<std::vector<size_t>> numbers {{1, 2, 3}, {4, 6, 8}, {7, 5, 1000}};
        GameBoard game_board_ = GameBoard(board_size_, hard_mode_);
    };
}
