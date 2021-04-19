//
// Created by pokey on 4/17/2021.
//
#include "slide_puzzle_app.h"

namespace slidepuzzle {

SlidePuzzleApp::SlidePuzzleApp() {
    ci::app::setWindowSize(kWindowSize, kMargin);
}

void SlidePuzzleApp::draw() {
    ci::Color background_color("gray");
    ci::gl::clear(background_color);

    slidepuzzle::GameBoard game(3);
    ci::gl::drawStringCentered(
            game.GetNum(),
            glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));
}

}
