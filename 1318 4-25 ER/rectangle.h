#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"

class rectangle_t{
      private:
        point_t ul, lr, center;
        int     length, height;
        color_t color;

    public:
        //constructors
        rectangle_t();
        rectangle_t(point_t, int, int, color_t);

        //setters
        void setUL(const point_t&);
        void setLR(const point_t&);
        void setColor(const color_t&);

        //getters
        point_t getUL() const;
        point_t getLR() const;
        color_t getColor() const;

        //displayers
        void display(SDL_Plotter&) const;
        void eraser (SDL_Plotter&) const;
        void eraser (SDL_Plotter&, color_t) const;
};

#endif // RECTANGLE_H_INCLUDED
