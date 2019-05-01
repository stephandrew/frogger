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
        //Constructor
        bug_t();

        //Setters
        void setColor(color_t);
        void setLocation(point_t);

        //Getters
        point_t getLocation();
        color_t getColor();

        //Displayers
        void display(SDL_Plotter& g);

        //Others
        bool isOn(point_t f);
};


#endif // BUG_H_INCLUDED
