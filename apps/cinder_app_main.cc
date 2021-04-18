//
// Created by pokey on 4/17/2021.
//
#include "slide_puzzle_app.h"

using slidepuzzle::SlidePuzzleApp;

void prepareSettings(SlidePuzzleApp::Settings* settings) {
    settings->setResizable(false);
}

CINDER_APP(SlidePuzzleApp, ci::app::RendererGl, prepareSettings);