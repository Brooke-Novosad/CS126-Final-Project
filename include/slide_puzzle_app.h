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
     * @param event
     */
    void mouseDown(ci::app::MouseEvent event) override;

    /**
    //might not need, use mousedown overrides
    void update() override;
**/
    const int kWindowSize = 875;
    const int kMargin = 500;

private:
    size_t board_size = 3;
    GameBoard game_board_ = GameBoard(board_size);
};
}