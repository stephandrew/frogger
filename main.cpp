#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "SDL_Plotter.h"
#include "point.h"
#include "rectangle.h"
#include "frog.h"
#include "log.h"
#include "title.h"
#include "startText.h"

using namespace std;

const int NUMBER_OF_LOGS = 4;
const int DISPLAY_HEIGHT = 1000;
const int DISPLAY_WIDTH  = 1000;

int main(int argc, char** argv)
{
    srand(time(0));
    SDL_Plotter g(DISPLAY_HEIGHT,DISPLAY_WIDTH);
    char key;
    frog_t frog;
    log_t logRight[NUMBER_OF_LOGS];//these logs will move to the right
    log_t logLeft [NUMBER_OF_LOGS];//these logs will move to the left
    rectangle_t river;

    title_t grass, water;
    grass = title_t(point_t (0,0), point_t (1000,800), color_t(0, 250, 0));
    water = title_t(point_t (0,801), point_t (1000,1000), color_t(0,10,220));
    bool click = false;
    int xLoc = 430, yLoc = 500;
    int titleSize = 3;
    int x, y;
    int row, col;

    double score = 0;

    grass.display(g);
    water.display(g);
    displayTitle(xLoc, yLoc, titleSize, g);
    g.update();

    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the right
        logRight[i].setLocation(point_t(i*(RATIO*LENGTH + 60),START_Y_RIGHT));

        //offset the logs that move to the left
        logLeft[i].setLocation(point_t(i*(RATIO*LENGTH + 60), START_Y_LEFT));
        //move the logs to the left
        logRight[i].setDirection(-1);
    }

    //make the river
    river.setColor(COLOR_WATER);
    river.setUL(point_t(0,265));
    river.setLR(point_t(DISPLAY_WIDTH-1, 437));

    while (!g.getQuit()) {

        while(!click){
            g.getMouseClick(x,y);
            if(x > 425 && x < 575){
                if(y > 480 && y < 520){
                    click = true;
                }
            }
        }

        g.clear();

        if (g.kbhit()) {

            key = g.getKey();

            switch (key){
                    case UP_ARROW:    frog.hopForward();
                         break;
                    case DOWN_ARROW:  frog.hopBack();
                         break;
                    case LEFT_ARROW:  frog.hopLeft();
                         break;
                    case RIGHT_ARROW: frog.hopRight();
                         break;
                    default: break; //nothing
            }
        }

        river.display(g);

        for (int i = 0; i < NUMBER_OF_LOGS; i++) {
            logRight[i].display(g);
            logLeft[i].display(g);
        }

        frog.display(g);

        g.update();
    }
    return 0;
}
