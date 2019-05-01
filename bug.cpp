#include "bug.h"

// Constructors
bug_t::bug_t()
{
    color = COLOR_BLACK;
    location = point_t(rand()%950, rand()%950);

    bug.setColor(color);
    bug.setUL(point_t(1, 1));
    bug.setLR(point_t(1.01, 1.01));
}

//Setters
void bug_t::setColor(color_t c)
{
    color = c;
    bug.setColor(color);
}
void bug_t::setLocation(point_t p)
{
    location.setX(p.getX());
    location.setY(p.getY());
}

//Getters
point_t bug_t::getLocation()
{
    return location;
}
color_t bug_t::getColor()
{
    return color;
}

//Displayers
void bug_t::display(SDL_Plotter& g)
{
    if (clock() >= movedAtTime + 5)
    { //if time has passed
        location.setX(location.getX()); //change the x by speed pixels

        //set corners of rectangle
        bug.setUL(point_t(location.getX(), location.getY()));
        bug.setLR(point_t(location.getX() + 10, location.getY() + 10));

        //remember when we moved
        movedAtTime = clock();
    }
    bug.display(g);
}

//Other
bool bug_t::isOn(point_t f){
    bool flag = false;

    if(f.getX() > bug.getUL().getX() && f.getX() < bug.getLR().getX()){
        if(f.getY() > bug.getUL().getY() && f.getY() < bug.getLR().getY()){
            flag = true;
        }
    }

    return flag;

    //get the point of the frogs location, pass it in on main
}






