#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include "SDL_Plotter.h"
#include "color.h"

using namespace std;

class point_t {
    private:
        int x, y;
        color_t color;

    public:
        point_t();
        point_t(int, int);

        void setX(int);    //setters
        void setY(int);

        int  getX() const; //getters
        int  getY() const;

        void display(ostream&) const;
        void display(SDL_Plotter&) const;

};

#endif // POINT_H_INCLUDED
