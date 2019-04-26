#include "startText.h"

void displayTitle(int& xLoc, int& yLoc, int size, SDL_Plotter& g) {
    printLetter("font/S.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("font/T.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("font/A.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("font/R.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("font/T.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
}
