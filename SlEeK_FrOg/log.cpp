#include "log.h"

///Constructors
log_t::log_t(){
    ratio = RATIO;
    color = COLOR_LOG;
    location = point_t(900,275);
    speed = -5;
    timeDelay = 25;
    length = 50;

    log.setColor(color);
    log.setUL(point_t(START_X_RIGHT, START_Y_RIGHT));
    log.setLR(point_t(START_X_RIGHT + ratio * length, START_Y_RIGHT + length));
}

///Setters
void log_t::setColor(color_t c){
    color = c;
    log.setColor(color);
}

void log_t::setLocation(point_t p){
    location.setX(p.getX());
    location.setY(p.getY());
}

void log_t::setDirection(int x){
    if (x < 0) {
        speed *= -1;
    }
}


///Getters
point_t log_t::getLocation(){
    return location;
}

color_t log_t::getColor(){
    return color;
}

double  log_t::getSpeed(){
    return speed;
}

double  log_t::getLength(){
    return length;
}

///Displayers
void log_t::display(SDL_Plotter& g){
    log.eraser(g, COLOR_WATER); //erase old log

    if (clock() >= movedAtTime + timeDelay){ //if time has passed
        move();//move the log
    }

    log.display(g); //display the log
}


///Others
void log_t::move(){
    location.setX(location.getX() + speed); //change the x by speed pixels

    if (speed > 0 && location.getX() >= 1000) {

        location.setX(-RATIO*length);

    }
    else if (speed < 0 && location.getX() < - RATIO*length) {
        location.setX(1000);
    }

    //set corners of rectangle
    log.setUL(point_t(location.getX(), location.getY()));
    log.setLR(point_t(location.getX() + 4.5 * length, location.getY() + length));

    //remember when we moved
    movedAtTime = clock();
}

/*void log_t::newLog(){ //having some issues with this rn, but should be able to fix it soon
    int x; //new x-coordinate

    if(rand()%2) {//random 1 or 0, if it's 0,
        x = 1000; //start on the right side of the screen
        speed = -5; //move to the left
    }
    else { //otherwise
        x = -length; //start off of the left side of the screen
        speed = 5; // move to the right
    }

    location = point_t(x, rand()%900); //set location

    timeDelay = rand()%10 + 15; //set new random time delay
}
*/
