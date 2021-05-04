//
// Created by pokey on 4/18/2021.
//
#include "menu.h"

using glm::vec2;

namespace slidepuzzle {

    Menu::Menu() { }

    void Menu::Display() const {
        ci::gl::clear(pink);

        ci::gl::drawStringCentered("Slide Puzzle", vec2(kWindowSize / 2, kWindowSize / 5),
                                   ci::Color(black), ci::Font(font, title_font));
        Draw3Titles();
        Draw4Titles();
        Draw5Titles();

        ci::gl::drawStringCentered("Click t to play hard mode puzzle that is solved",
                                   vec2(kWindowSize / 2, 3 * kWindowSize / 4),
                                   black, ci::Font(font, small_font));
        ci::gl::drawStringCentered("Click r to play easy mode puzzle that is solved",
                                   vec2(kWindowSize / 2, (3 * kWindowSize / 4) + small_font),
                                   black, ci::Font(font, small_font));
        ci::gl::drawStringCentered("Click s to start!",
                                   vec2(kWindowSize / 2, (4 * kWindowSize / 5) + small_font),
                                   black, ci::Font(font, big_font));

    }

    void Menu::Draw3Titles() const {
        ci::gl::drawStringCentered("3 X 3 Board", vec2(kWindowSize / 5, kWindowSize / 2),
                                   black, ci::Font(font, big_font));

        ci::gl::drawStringCentered("Hard Mode", vec2(kWindowSize / 5, (kWindowSize / 2) + big_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press h", vec2(kWindowSize / 5, (kWindowSize / 2) + med_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Easy Mode", vec2(kWindowSize / 5, 2 * kWindowSize / 3),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press e", vec2(kWindowSize / 5, (2 * kWindowSize / 3) + small_font),
                                   black, ci::Font(font, small_font));
    }

    void Menu::Draw4Titles() const {
        ci::gl::drawStringCentered("4 X 4 Board", vec2(kWindowSize / 2, kWindowSize / 2),
                                   black, ci::Font(font, big_font));

        ci::gl::drawStringCentered("Hard Mode", vec2(kWindowSize / 2, (kWindowSize / 2) + big_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press d", vec2(kWindowSize / 2, (kWindowSize / 2) + med_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Easy Mode", vec2(kWindowSize / 2, 2 * kWindowSize / 3),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press p", vec2(kWindowSize / 2, (2 * kWindowSize / 3) + small_font),
                                   black, ci::Font(font, small_font));

    }

    void Menu::Draw5Titles() const {
        ci::gl::drawStringCentered("5 X 5 Board", vec2(4 * kWindowSize / 5, kWindowSize / 2),
                                   black, ci::Font(font, big_font));

        ci::gl::drawStringCentered("Hard Mode", vec2(4 * kWindowSize / 5, (kWindowSize / 2) + big_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press g", vec2(4 * kWindowSize / 5, (kWindowSize / 2) + med_font),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Easy Mode", vec2(4 * kWindowSize / 5, 2 * kWindowSize / 3),
                                   black, ci::Font(font, small_font));

        ci::gl::drawStringCentered("Press y",
                                   vec2(4 * kWindowSize / 5, (2 * kWindowSize / 3) + small_font),
                                   black, ci::Font(font, small_font));
    }
}