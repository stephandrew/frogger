#include "color.h"
void printColor(string fname, int xLoc, int yLoc, int size, SDL_Plotter& g)
{
    ifstream file;
    int row, col;
    char ch;
    color_t c;
    bool p;

    file.open(fname.c_str());
      if(!file)
      {
          cout << "Error: File Not Open" << endl;
      }
      file >> row >> col;
      for(int y = 0; y < row; y++)
      {
          for(int x = 0; x < col; x++)
          {
              p = true;
              file >> ch;
              switch (ch)
              {
                  case '0': p = false;
                            break;
                  case '1': c = COLOR_BLACK;
                            break;
                  case '2': c = COLOR_RED;
                            break;
                  case '3': c = COLOR_ORANGE;
                            break;
                  case '4': c = COLOR_YELLOW;
                            break;
                  case '5': c = COLOR_GREEN;
                            break;
                  case '6': c = COLOR_BLUE;
                            break;
                  case '7': c = COLOR_PURPLE;
                            break;
                  case '8': c = COLOR_BROWN;
                            break;
                  case '9': c = COLOR_WHITE;
                            break;
              }
              if (p) {
                for(int deltaX = 0; deltaX < size; deltaX++){
                      for(int deltaY = 0; deltaY < size; deltaY++){
                          g.plotPixel(x*size + xLoc + deltaX, y*size + yLoc + deltaY, c.R, c.G, c.B);
                      }
                  }
              }

          }
      }
}
