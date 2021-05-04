//
// Created by pokey on 4/18/2021.
//
#ifndef FINAL_PROJECT_MENU_H
#define FINAL_PROJECT_MENU_H
#include "cinder/gl/gl.h"
#endif //FINAL_PROJECT_MENU_H

namespace slidepuzzle {
    /**
     * This class is for displaying the menu at the start of the game.
     */
    class Menu {
    public:
        /**
         * Constructor for the menu class.
         */
        Menu();

        /**
         * Displays the slide puzzle menu
         */
        void Display() const;

        const int kWindowSize = 875;

    private:
        /**
         * A helper that draws the instructions for 3x3 games.
         */
        void Draw3Titles() const;

        /**
         * A helper that draws the instructions for 4x4 games.
         */
        void Draw4Titles() const;

        /**
         * A helper that draws the instructions for 5x5 games.
         */
        void Draw5Titles() const;

        ci::Color black = "black";
        ci::Color pink = "pink";
        float small_font = 30;
        float big_font = 50;
        float med_font = 75;
        float title_font = 150;
        std::string font = "Arial";

    };


}