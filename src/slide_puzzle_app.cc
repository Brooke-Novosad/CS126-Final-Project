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

    void SlidePuzzleApp::mouseDown(ci::app::MouseEvent event) {
        game_board_.ClickTile(event.getPos());
    }

    void SlidePuzzleApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_UP:
                game_board_.SlideTile(up);
                break;
            case ci::app::KeyEvent::KEY_DOWN:
                game_board_.SlideTile(down);
                break;
            case ci::app::KeyEvent::KEY_LEFT:
                game_board_.SlideTile(left);
                break;
            case ci::app::KeyEvent::KEY_RIGHT:
                game_board_.SlideTile(right);
                break;
        }
    }

}

