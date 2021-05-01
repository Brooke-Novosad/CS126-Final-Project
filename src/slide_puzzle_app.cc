//
// Created by pokey on 4/17/2021.
//
#include "slide_puzzle_app.h"

namespace slidepuzzle {

    SlidePuzzleApp::SlidePuzzleApp() : game_board_{GameBoard(numbers)} {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void SlidePuzzleApp::draw() {
        ci::Color background_color("gray");
        ci::gl::clear(background_color);
        if (!game_board_.IsGameWon()) {
            game_board_.Display();
        } else {
            ci::gl::drawStringCentered(
                    "You Win!",
                    glm::vec2(kWindowSize / 2, kWindowSize / 2), ci::Color("white"),
                    ci::Font(font, font_size));
        }
    }

    void SlidePuzzleApp::mouseDown(ci::app::MouseEvent event) {
        game_board_.ClickTile(event.getPos());
    }

    //use enums for directions instead of strings
    void SlidePuzzleApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_UP:
                game_board_.SlideTile(GameBoard::up);
                break;
            case ci::app::KeyEvent::KEY_DOWN:
                game_board_.SlideTile(GameBoard::down);
                break;
            case ci::app::KeyEvent::KEY_LEFT:
                game_board_.SlideTile(GameBoard::left);
                break;
            case ci::app::KeyEvent::KEY_RIGHT:
                game_board_.SlideTile(GameBoard::right);
                break;
        }
    }

}

