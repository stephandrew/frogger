#include "point.h"

//constructors
point_t::point_t() {
    x = 0; //this is to prevent arbitrary trash
    y = 0;
}

point_t::point_t(int a, int b) {
    x = a;
    y = b;
}

//setters
void point_t::setX(int a) {
    x = a;
    return;
}

void point_t::setY(int a) {
    y = a;
    return;
}

//getters
int  point_t::getX() const{
    return x;
}

int  point_t::getY() const{
    return y;
}

//displayers
void point_t::display(ostream& out) const{
    out << "(" << getX() << ", " << getY() << ")";
}

void point_t::display(SDL_Plotter& g) const{
    g.plotPixel(getX(), getY(), 0, 0, 0);
}

