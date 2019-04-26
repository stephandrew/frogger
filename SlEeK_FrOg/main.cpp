#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "SDL_Plotter.h"
#include "point.h"
#include "color.h"
#include "rectangle.h"
#include "frog.h"
#include "log.h"

using namespace std;

const int NUMBER_OF_LOGS = 4;
const int DISPLAY_HEIGHT = 1000;
const int DISPLAY_WIDTH  = 1000;
const int NUM_OF_STRIPES = 5;

int main(int argc, char** argv)
{
    srand(time(0));
    SDL_Plotter g(DISPLAY_HEIGHT,DISPLAY_WIDTH);
    char key;
    frog_t frog;
    log_t logRight[NUMBER_OF_LOGS];//these logs will move to the right
    log_t logLeft [NUMBER_OF_LOGS];//these logs will move to the left
    rectangle_t river, road;
    rectangle_t roadStripes[NUM_OF_STRIPES];
    int stripeLength = DISPLAY_WIDTH/(2*NUM_OF_STRIPES);
    int stripeWidth  = 20;

    //make the logs
    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the right
        logRight[i].setLocation(point_t(i*(RATIO*LENGTH + 60),START_Y_RIGHT));

        //offset the logs that move to the left
        logLeft[i].setLocation(point_t(i*(RATIO*LENGTH + 60),
                                       START_Y_LEFT + LENGTH));
        //move the logs to the left
        logRight[i].setDirection(-1);
    }

    //make the river
    river.setColor(COLOR_WATER);
    river.setUL(point_t(0,265));
    river.setLR(point_t(DISPLAY_WIDTH-1, 437));

    //make the road
    road.setColor(COLOR_BLACK);
    road.setUL(point_t(0, 725));
    road.setLR(point_t(DISPLAY_WIDTH-1, 874));

    //road stripes



    while (!g.getQuit()) {

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

        //road.display(g);

        //for (int i = 0; i < NUM_OF_STRIPES; i++){
        //    roadStripes[i].display(g);
        //}

        frog.display(g);

        g.update();
    }
    return 0;
}
