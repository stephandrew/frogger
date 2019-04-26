#include "title.h"

    title_t::title_t(){
        titleUL.setX(0);
        titleUL.setY(0);

        tileLR.setX(100);
        tileLR.setY(100);
    }
    title_t::title_t(point_t a, point_t b, color_t c){
        titleUL = a;
        tileLR = b;
        color = c;
    }

    void title_t::setUL(const point_t& a){
        titleUL = a;
    }

    void title_t::setLR(const point_t& b){
        tileLR = b;
    }

    void title_t::setColor(const color_t& c){
        color = c;
    }

    point_t title_t::getUL() const{
        return titleUL;
    }

    point_t title_t::getLR() const{
        return tileLR;
    }

    color_t title_t::getColor() const{
        return color;
    }

    void title_t::display(SDL_Plotter& g) const{

        for (int y = titleUL.getY(); y <= tileLR.getY(); y++) {
            for (int x = titleUL.getX(); x <= tileLR.getX(); x++) {
                if ((x <= g.getCol()) && (y < g.getRow()) && x >= 0 && y >= 0) {
                    g.plotPixel(x, y, color.R, color.G, color.B);
                }

            }
        }

    }

