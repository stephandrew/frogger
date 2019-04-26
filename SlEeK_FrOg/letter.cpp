#include "letter.h"

void printLetter(string fname, int xLoc, int yLoc, int size, SDL_Plotter& g){

    ifstream file;
    int row, col;
    char ch;

    file.open(fname);

    if(!file){
        cout << "Error" << endl;
    }

    file >> row >> col;
    for (int y = 0; y < row; y++){
        for (int x = 0; x < col; x ++) {
            file >> ch;
            if (ch == '1') {
                for (int deltaX = 0; deltaX < size; deltaX++){
                    for(int deltaY = 0; deltaY < size; deltaY++){
                        g.plotPixel(xLoc + x*size + deltaX, yLoc + y*size + deltaY, 0, 0, 0);
                    }
                }
            }
        }
    }
    file.close();

    return;
}
