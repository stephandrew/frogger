#include "frog.h"

//constructors
    frog_t::frog_t(){
        size      = 25;
        hopSize   = 3;
        color     = COLOR_FROG;
        location  = point_t(500, 0);
        prevLoc   = location;
        hasHopped = false;
        onLog     = false;
        timeDelay = 40;
        body.setColor(color);
        body.setUL(point_t(location.getX(), location.getY()));
        body.setLR(point_t(location.getX() + size, location.getY() + size));
        body2.setUL(point_t(prevLoc.getX(), prevLoc.getY()));
        body2.setLR(point_t(prevLoc.getX() + size, prevLoc.getY() + size));
    }

//setters
    void frog_t::setLocation(point_t p, rectangle_t& b){
        location = p;
        b.setUL(point_t(location.getX(), location.getY()));
        b.setLR(point_t(location.getX() + size, location.getY() + size));
    }

    void frog_t::setColor(color_t c){
        color = c;
        body.setColor(color);
    }

    void frog_t::setSize(int s){
        size = s;
    }

    void frog_t::setHasHopped(bool a){
        hasHopped = a;
    }

    void frog_t::setHopSize(int s){
        hopSize = s;
    }

//getters
    point_t frog_t::getLocation() const{
        return location;
    }

    color_t frog_t::getColor() const{
        return color;
    }

    int frog_t::getSize() const{
        return size;
    }

    bool frog_t::getHasHopped() const{
        return hasHopped;
    }

    int  frog_t::getHopSize() const{
        return hopSize;
    }


//displayers
    void frog_t::display(SDL_Plotter& g) {
        if (getHasHopped()) {
            setHasHopped(false);
            if (onLog) {
                body2.eraser(g, COLOR_LOG);
            } else {
                body2.eraser(g);
            }


            setLocation(location, body2);
        }

        body.display(g);
    }

//actions
    void frog_t::hopForward(){
        prevLoc = location;
        setLocation(point_t(location.getX(), location.getY() - hopSize * size), body);
        hasHopped = true;
    }

    void frog_t::hopBack(){
        prevLoc = location;
        setLocation(point_t(location.getX(), location.getY() + hopSize * size), body);
        hasHopped = true;
    }

    void frog_t::hopLeft(){
        prevLoc = location;
        setLocation(point_t(location.getX() - hopSize * size, location.getY()), body);
        hasHopped = true;
    }

    void frog_t::hopRight(){
        prevLoc = location;
        setLocation(point_t(location.getX() + hopSize * size, location.getY()), body);
        hasHopped = true;
    }

    void frog_t::move(double speed){
        if (clock() >= movedAtTime + timeDelay){ //if time has passed
            location.setX(location.getX() + speed); //change the x by speed pixels

            if (speed > 0 && location.getX() >= 1000) {
                        cout << "frog die" << endl;
            }
            else if (speed < 0 && location.getX() < 0) {
                        cout << "frog die" << endl;
            }

            //set corners of rectangle
            body.setUL(point_t(location.getX(), location.getY()));
            body.setLR(point_t(location.getX() + size, location.getY() + size));
            hasHopped = true;
            onLog = true;

            //remember when we moved
            movedAtTime = clock();
        }
    }
