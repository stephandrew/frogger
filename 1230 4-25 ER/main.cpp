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

    ///title screen stuff
    title_t grass, water;
    grass = title_t(point_t (0,0), point_t (1000,800), color_t(0, 250, 0));
    water = title_t(point_t (0,801), point_t (1000,1000), color_t(0,10,220));
    bool click = false;
    int startTextX = 430, startTextY = 500;
    int titleSize = 3;
    int mouseClickX, mouseClickY;

    grass.display(g);
    water.display(g);
    displayTitle(startTextX, startTextY, titleSize, g);
    g.update();

    //Environment stuff
    log_t logRight[NUMBER_OF_LOGS];//these logs will move to the right
    log_t logLeft [NUMBER_OF_LOGS];//these logs will move to the left
    rectangle_t river;
    rectangle_t road, stripes;

    //make the river
    river.setColor(COLOR_WATER);
    river.setUL(point_t(0,265));
    river.setLR(point_t(DISPLAY_WIDTH-1, 437));

    double score = 0;


    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the right
        logRight[i].setLocation(point_t(i*(RATIO*LENGTH + 60),START_Y_RIGHT));
        //move the logs to the right
        logRight[i].setDirection(-1);
    }

    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the left
        logLeft[i].setLocation(point_t(i*(RATIO*LENGTH + 60), START_Y_LEFT));
    }

    while (!g.getQuit()) {


        while(!click){
            g.getMouseClick(mouseClickX,mouseClickY);
            if(mouseClickX > 425 && mouseClickX < 575){
                if(mouseClickY > 480 && mouseClickY < 520){
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
