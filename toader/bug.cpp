#include "bug.h"

bug_t::bug_t()
{
    color = COLOR_BLACK;
    location = point_t(rand()%950, rand()%950);
    size = 5;

    bug.setColor(color);
    bug.setUL(point_t(259, 269));
    bug.setLR(point_t(259 + 10, 269 + 10));
}
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
point_t bug_t::getLocation()
{
    return location;
}
color_t bug_t::getColor()
{
    return color;
}
void bug_t::display(SDL_Plotter& g)
{
    if (clock() >= movedAtTime + 5000)
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






