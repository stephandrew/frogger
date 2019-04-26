#include "SDL_Plotter.h"
#include "color.h"
#include "rectangle.h"
#include "letter.h"

#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED

class title_t{
    private:
        point_t ul, lr;
        color_t color;

    public:
        title_t();
        title_t(point_t, point_t, color_t);

        void setUL(const point_t&);
        void setLR(const point_t&);
        void setColor(const color_t&);

        point_t getUL() const;
        point_t getLR() const;
        color_t getColor() const;

        void display(SDL_Plotter&) const;
};


#endif // TITLE_H_INCLUDED
