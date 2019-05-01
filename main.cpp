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
#include "bug.h"
#include "text.h"

using namespace std;

const int NUMBER_OF_BUGS = 5;
const int NUMBER_OF_LOGS = 3;
const int DISPLAY_HEIGHT = 1000;
const int DISPLAY_WIDTH  = 1000;
const int NUMBER_OF_STRIPES = 5;

int main(int argc, char** argv)
{
    srand(time(0));
    SDL_Plotter g(DISPLAY_HEIGHT,DISPLAY_WIDTH);
    char key;
    frog_t frog;
    bool dead = false;
    int a[] = {1,2,3};

    ///title screen stuff
    title_t grass, water;
    grass = title_t(point_t (0,0), point_t (1000,800), color_t(0, 250, 0));
    water = title_t(point_t (0,801), point_t (1000,1000), color_t(0,10,220));
    bool click = false;
    int mouseClickX, mouseClickY;

    grass.display(g);
    water.display(g);
    displayText("START", 3, point_t(430,500), g);
    displayScore(a, 3, point_t(800,100), g);
    g.update();

    while(!click){
        if (g.kbhit()) {
            click = true;
        }
    }

    ///Environment stuff
    rectangle_t river;
    log_t logRight[NUMBER_OF_LOGS];//these logs will move to the right
    log_t logLeft [NUMBER_OF_LOGS];//these logs will move to the left
    rectangle_t road, stripes[NUMBER_OF_STRIPES];
    int stripeLength = DISPLAY_WIDTH/(2*NUMBER_OF_STRIPES);
    bool onLog = false;
    bool onBug;

    //make the river
    river.setColor(COLOR_WATER);
    river.setUL(point_t(0,265));
    river.setLR(point_t(DISPLAY_WIDTH-1, 437));

    //make the logs
    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the right
        logRight[i].setLocation(point_t(2*i*RATIO*LENGTH + 80,START_Y_RIGHT));
        //move the logs to the right
        logRight[i].setDirection(-1);
    }

    for (int i = 0; i < NUMBER_OF_LOGS; i++){
        //offset the logs that move to the left
        logLeft[i].setLocation(point_t(2*i*RATIO*LENGTH + 80, START_Y_LEFT));
    }

    //make the road
    road.setColor(COLOR_ROAD);
    road.setUL(point_t(0, 575));
    road.setLR(point_t(DISPLAY_WIDTH-1, 812));

    //make the stripes
    for (int i = 0; i < NUMBER_OF_STRIPES; i++) {
        stripes[i].setColor(COLOR_STRIPES);
        stripes[i].setUL(point_t(2*i*stripeLength, 677));
        stripes[i].setLR(point_t((2*i+1)*stripeLength, 697));
    }

    ///other characters
    bug_t bug[NUMBER_OF_BUGS];

    for (int i = 0; i < NUMBER_OF_BUGS; i++){
        //initialize bugs at random locations
        bug[i].setLocation(point_t(rand()%1000,rand()%1000));
    }


    ///other stuff
    double score = 0;

    ///GAME LOOP///
    while (!g.getQuit()) {

        //title screen

        g.clear();
        //end title screen

        ///input
        if (g.kbhit()) {
            key = g.getKey();

            cout << key << endl;

            switch (key){
                    case UP_ARROW:    frog.hopForward();
                         cout << "up" << endl;
                         break;
                    case DOWN_ARROW:  frog.hopBack();
                         cout << "down" << endl;
                         break;
                    case LEFT_ARROW:  frog.hopLeft();
                         cout << "left" << endl;
                         break;
                    case RIGHT_ARROW: frog.hopRight();
                         cout << "right" << endl;
                         break;
            }
            cout << endl;
        }

        ///process
        //on a log?
        onLog = false;
        for (int i = 0; i < NUMBER_OF_LOGS; i++) {
            if(logLeft[i].inOn(frog.getLocation())){
                frog.move(logLeft[i].getSpeed());
                onLog = true;
            }
            else if(logRight[i].inOn(frog.getLocation())){
                frog.move(logRight[i].getSpeed());
                onLog = true;
            }
        }

        //in the river?
        if (!onLog && river.isOn(frog.getLocation())) {
            dead = true;
        }

        for(int i = 0; i < NUMBER_OF_LOGS; i++){
            logRight[i].display(g);
            logLeft[i].display(g);
        }

        if (dead) {
            frog.setColor(COLOR_BLACK);
            g.setQuit(1);
        }

        //is on bug??
        for(int i = 0; i < NUMBER_OF_BUGS; i++)
        {
            if(bug[i].isOn(frog.getLocation()))
            {
                onBug = true;
            }
            if(onBug)
            {
                score++;
            }
        }

        ///output
        river.display(g);

        for (int i = 0; i < NUMBER_OF_LOGS; i++) {
            logRight[i].display(g);
            logLeft[i].display(g);
        }

        road.display(g);
        for(int i = 0; i < NUMBER_OF_STRIPES; i++) {
            stripes[i].display(g);
        }

        for(int i = 0; i < NUMBER_OF_BUGS; i++){
            bug[i].display(g);
        }

        //frog MUST display last
        frog.display(g);

        ///Update screen
        g.update();
    }
    return 0;
}
