#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

#include <string>
#include <fstream>
#include "SDL_Plotter.h"

using namespace std;

void printLetter(string fname, int x, int y, int size, SDL_Plotter& g);


#endif // LETTER_H_INCLUDED
