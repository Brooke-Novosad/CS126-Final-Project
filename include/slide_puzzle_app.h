//
// Created by pokey on 4/17/2021.
//
#pragma once

#ifndef FINAL_PROJECT_SLIDE_PUZZLE_APP_H
#define FINAL_PROJECT_SLIDE_PUZZLE_APP_H

#endif //FINAL_PROJECT_SLIDE_PUZZLE_APP_H

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
    const int kWindowSize = 1000;
    const int kMargin = 500;

};


}