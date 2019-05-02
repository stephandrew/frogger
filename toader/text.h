#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "SDL_Plotter.h"
#include "letter.h"
#include "point.h"

void displayText(string, int, point_t, SDL_Plotter&);

void displayScore(int[], int, point_t, SDL_Plotter&);

#endif // TEXT_H_INCLUDED
