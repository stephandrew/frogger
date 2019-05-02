#include "rectangle.h"

///constructors
    rectangle_t::rectangle_t(){
        ul.setX(0);
        ul.setY(0);

        lr.setX(100);
        lr.setY(100);
    }

    rectangle_t::rectangle_t(point_t a, int length, int height, color_t c){
        ul = a;
        lr = point_t(ul.getX() + length, ul.getY() + height);
        color = c;
    }

///setters
    void rectangle_t::setUL(const point_t a){
        ul = a;
    }

    void rectangle_t::setLR(const point_t b){
        lr = b;
    }

    void rectangle_t::setColor(const color_t c){
        color = c;
    }

///getters
    point_t rectangle_t::getUL() const{
        return ul;
    }

    point_t rectangle_t::getLR() const{
        return lr;
    }

    color_t rectangle_t::getColor() const{
        return color;
    }

///displayers
    void rectangle_t::display(SDL_Plotter& g) const{

        for (int y = ul.getY(); y <= lr.getY(); y++) {
            for (int x = ul.getX(); x <= lr.getX(); x++) {
                if ((x <= g.getCol()) && (y < g.getRow()) && x >= 0 && y >= 0) {
                    g.plotPixel(x, y, color.R, color.G, color.B);
                }
            }
        }
    }

    void rectangle_t::eraser(SDL_Plotter& g) const{
        for (int y = ul.getY(); y <= lr.getY(); y++) {
            for (int x = ul.getX(); x <= lr.getX(); x++) {
                if ((x <= g.getCol()) && (y < g.getRow()) && x >= 0 && y >= 0) {
                    g.plotPixel(x, y, 255, 255, 255);
                }
            }
        }
    }

    void rectangle_t::eraser (SDL_Plotter& g, color_t c) const{
        for (int y = ul.getY(); y <= lr.getY(); y++) {
            for (int x = ul.getX(); x <= lr.getX(); x++) {
                if ((x <= g.getCol()) && (y < g.getRow()) && x >= 0 && y >= 0) {
                    g.plotPixel(x, y, c.R, c.G, c.B);
                }

            }
        }
    }

///others

bool rectangle_t::isOn(point_t f){
    bool flag = false;

    if(f.getX() > ul.getX() && f.getX() < lr.getX()){
        if(f.getY() > ul.getY() && f.getY() < lr.getY()){
            flag = true;
        }
    }

    return flag;

    //get the point of the frogs location, pass it in on main
}
