#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <string>
#include "SDL_Plotter.h"
#include <fstream>
using namespace std;

struct color_t {
    int R, G, B;

    color_t() {
        R = G = B = 0;
    }

    color_t (int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }
};

void printColor(string fname, int xLoc, int yLoc, int size, SDL_Plotter& g);
void readColor(string fname, int xLoc, int yLoc, int size, SDL_Plotter& g);

//general colors
const color_t COLOR_WHITE (255, 255, 255);
const color_t COLOR_BLACK (0, 0, 0);
const color_t COLOR_GREEN (0, 255, 0);
const color_t COLOR_RED   (255, 0, 0);
const color_t COLOR_YELLOW(240, 229, 25);
const color_t COLOR_BROWN (120, 70, 0);
const color_t COLOR_BLUE  (0, 0, 255);
const color_t COLOR_PURPLE(160, 58, 161);
const color_t COLOR_ORANGE(255, 127, 39);
const color_t COLOR_PINK  (232, 128, 161);

//object colors
const color_t COLOR_GRASS(232, 128, 161);
const color_t COLOR_WATER(0, 75, 250);
const color_t COLOR_FROG (0, 220, 30);
const color_t COLOR_LOG  (120, 70, 0);

#endif // COLOR_H_INCLUDED
