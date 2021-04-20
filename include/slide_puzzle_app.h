//
// Created by pokey on 4/17/2021.
//
#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_board.h"

namespace slidepuzzle {

class SlidePuzzleApp : public ci::app::App {

public:
    SlidePuzzleApp();

    void draw() override;

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