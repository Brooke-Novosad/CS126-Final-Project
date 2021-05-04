//
// Created by pokey on 4/17/2021.
//
#include "slide_puzzle_app.h"

namespace slidepuzzle {

    SlidePuzzleApp::SlidePuzzleApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        curr_game_state_ = menu;
    }

    void SlidePuzzleApp::draw() {
        ci::Color background_color("gray");
        ci::gl::clear(background_color);
        if (curr_game_state_ == menu) {
            game_menu_.Display();
        } else if (curr_game_state_ == playGame) {
            if (!game_board_.IsGameWon()) {
                game_board_.Display();
            } else {
                ci::gl::drawStringCentered(
                        "You Win!",
                        glm::vec2(kWindowSize / 2, kWindowSize / 2), white,
                        ci::Font(font, font_size));
                ci::gl::drawStringCentered(
                        "To play again, press q",
                        glm::vec2(kWindowSize / 2, 2 * kWindowSize / 3), white,
                        ci::Font(font, font_size1));
            }
        }
    }

    void SlidePuzzleApp::mouseDown(ci::app::MouseEvent event) {
        game_board_.ClickTile(event.getPos());
    }

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
            case ci::app::KeyEvent::KEY_h:
                board_size_ = 3;
                hard_mode_ = true;
                break;
            case ci::app::KeyEvent::KEY_e:
                board_size_ = 3;
                hard_mode_ = false;
                break;
            case ci::app::KeyEvent::KEY_d:
                board_size_ = 4;
                hard_mode_ = true;
                break;
            case ci::app::KeyEvent::KEY_p:
                board_size_ = 4;
                hard_mode_ = false;
                break;
            case ci::app::KeyEvent::KEY_g:
                board_size_ = 5;
                hard_mode_ = true;
                break;
            case ci::app::KeyEvent::KEY_y:
                board_size_ = 5;
                hard_mode_ = false;
                break;
            case ci::app::KeyEvent::KEY_t:
                game_board_ = GameBoard(numbers, true);
                curr_game_state_ = playGame;
                break;
            case ci::app::KeyEvent::KEY_r:
                game_board_ = GameBoard(numbers, false);
                curr_game_state_ = playGame;
                break;
            case ci::app::KeyEvent::KEY_s:
                game_board_ = GameBoard(board_size_, hard_mode_);
                curr_game_state_ = playGame;
                break;
            case ci::app::KeyEvent::KEY_q:
                curr_game_state_ = menu;
                break;
        }
    }
}

