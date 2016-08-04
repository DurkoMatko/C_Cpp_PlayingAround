#include <iostream>
#include "point.h"

using namespace std;

// POINT CLASS

//CONSTRUCTOR
point::point(double x,double y):
    x(x),
    y(y){}


double point::getx() const {
    return x;
}

void point::setx(double v){
    x=v;
}


double point::gety() const {
    return y;
}

void point::sety(double v){
    y=v;
}


point operator+(point& p1, point& p2){
    point sum = point(p1.getx()+p2.getx(),p1.gety()+p2.gety());
    return sum;
}

ostream& operator<< (ostream& out,const point& p){
    out << "(" << p.getx() << "," << p.gety() << ")";
    return out;
}

