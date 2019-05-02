#ifndef BUG_H_INCLUDED
#define BUG_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "rectangle.h"
#include <cmath>
#include <ctime>

class bug_t
{
    private:
        point_t location;
        color_t color;
        rectangle_t bug;
        int size;
        double movedAtTime;

    public:
        bug_t();
        void setColor(color_t);
        void setLocation(point_t);
        point_t getLocation();
        color_t getColor();
        void display(SDL_Plotter& g);

};


#endif // BUG_H_INCLUDED
