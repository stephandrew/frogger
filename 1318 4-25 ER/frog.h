#ifndef FROG_H_INCLUDED
#define FROG_H_INCLUDED

#include "point.h"
#include "color.h"
#include "rectangle.h"
#include "SDL_Plotter.h"

class frog_t {
    private:
        point_t     location;
        point_t     prevLoc;
        color_t     color;
        rectangle_t body, body2;
        int         size, hopSize;
        bool        hasHopped;

    public:
        //constructors
        frog_t();
        //frog_t();

        //setters
        void setLocation(point_t, rectangle_t&);
        void setColor(color_t);
        void setSize(int);
        void setHasHopped(bool);
        void setHopSize(int);

        //getters
        point_t getLocation() const;
        color_t getColor() const;
        int     getSize() const;
        bool    getHasHopped() const;
        int     getHopSize() const;

        //displayers
        void display(SDL_Plotter&);

        //actions
        void hopForward();
        void hopBack();
        void hopLeft();
        void hopRight();


};

#endif // FROG_H_INCLUDED
