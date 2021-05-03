//
// Created by pokey on 4/18/2021.
//

#ifndef FINAL_PROJECT_MENU_H
#define FINAL_PROJECT_MENU_H
#include "cinder/gl/gl.h"
#endif //FINAL_PROJECT_MENU_H

namespace slidepuzzle {

    class Menu {
    public:

        Menu();

        void Display() const;

        const int kWindowSize = 875;

    private:
        void Draw3Titles() const;

        void Draw4Titles() const;

        void Draw5Titles() const;

    };


}