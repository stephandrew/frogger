#include "startText.h"

void displayTitle(int& startTextX, int& startTextY, int size, SDL_Plotter& g) {
    printLetter("font/S.txt",startTextX, startTextY, size, g);
    startTextX += size * 10;
    printLetter("font/T.txt",startTextX, startTextY, size, g);
    startTextX += size * 10;
    printLetter("font/A.txt",startTextX, startTextY, size, g);
    startTextX += size * 10;
    printLetter("font/R.txt",startTextX, startTextY, size, g);
    startTextX += size * 10;
    printLetter("font/T.txt",startTextX, startTextY, size, g);
    startTextX += size * 10;
}
