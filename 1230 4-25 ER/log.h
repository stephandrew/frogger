#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "rectangle.h"
#include <cmath>
#include <ctime>

const int START_X_RIGHT = 900;
const int START_Y_RIGHT = 287;
const int START_X_LEFT  = 0;
const int START_Y_LEFT  = 362;
const int LENGTH        = 50;
const int RATIO         = 5.06;

class log_t
{
    private:
        int ratio;
        point_t location;
        color_t color;
        rectangle_t log;
        double speed, length;
        double movedAtTime, timeDelay;

    public:
        //Constructors
        log_t();

        //Setters
        void setColor(color_t);
        void setLocation(point_t);
        void setDirection(int);

        //Getters
        point_t getLocation();
        color_t getColor();
        double  getSpeed();
        double  getLength();

        //Displayers
        void display(SDL_Plotter&);

        //Others
        void move();
        //void newLog();

};

#endif // LOG_H_INCLUDED
