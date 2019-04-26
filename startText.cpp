#include "startText.h"

void displayTitle(int& xLoc, int& yLoc, int size, SDL_Plotter& g) {
    printLetter("S.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("T.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("A.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("R.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
    printLetter("T.txt",xLoc, yLoc, size, g);
    xLoc += size * 10;
}
