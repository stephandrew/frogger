#include "title.h"

    title_t::title_t(){
        ul.setX(0);
        ul.setY(0);

        lr.setX(100);
        lr.setY(100);
    }
    title_t::title_t(point_t a, point_t b, color_t c){
        ul = a;
        lr = b;
        color = c;
    }

    void title_t::setUL(const point_t& a){
        ul = a;
    }

    void title_t::setLR(const point_t& b){
        lr = b;
    }

    void title_t::setColor(const color_t& c){
        color = c;
    }

    point_t title_t::getUL() const{
        return ul;
    }

    point_t title_t::getLR() const{
        return lr;
    }

    color_t title_t::getColor() const{
        return color;
    }

    void title_t::display(SDL_Plotter& g) const{

        for (int y = ul.getY(); y <= lr.getY(); y++) {
            for (int x = ul.getX(); x <= lr.getX(); x++) {
                if ((x <= g.getCol()) && (y < g.getRow()) && x >= 0 && y >= 0) {
                    g.plotPixel(x, y, color.R, color.G, color.B);
                }

            }
        }

    }

