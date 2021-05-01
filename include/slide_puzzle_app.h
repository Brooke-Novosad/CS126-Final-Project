//
// Created by pokey on 4/17/2021.
//
#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_board.h"

namespace slidepuzzle {

/**
* An app for visualising the slide puzzle game.
*/
    class SlidePuzzleApp : public ci::app::App {

    public:
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

        /**
        //might not need, use mousedown overrides
        void update() override;
     **/
        const int kWindowSize = 875;
        const int kMargin = 500;

    private:
        std::string font = "Arial";
        float font_size = 100;
        size_t board_size_ = 3;
        // For showing win screen
        std::vector<std::vector<size_t>> numbers {{1, 2, 3}, {4, 6, 8}, {7, 5, 1000}};
        GameBoard game_board_;
    };
}
