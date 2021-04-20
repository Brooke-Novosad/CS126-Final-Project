//
// Created by pokey on 4/17/2021.
//
#include "slide_puzzle_app.h"

namespace slidepuzzle {

SlidePuzzleApp::SlidePuzzleApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void SlidePuzzleApp::draw() {
    ci::Color background_color("gray");
    ci::gl::clear(background_color);

    game_board_.Display();
}

}
