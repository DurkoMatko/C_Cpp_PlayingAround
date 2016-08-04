#include "Shape.h"
#include <iostream>

using namespace std;

Circle::Circle(int xcor,int ycor, int r){
    x=xcor;
    y=ycor;
    radius=r;
};

void Circle::setX(int xcor){
    x=xcor;
};

void Circle::setY(int ycor){
    y=ycor;
};

int Circle::getX()const{
    return x;
};

int Circle::getY()const{
    return y;
};

int Circle::getRadius()const{
    return radius;
};

void Circle::draw()const{
    cout<< "drawing circle at: " << getX() << "," << getY() <<
            " with a radius: " << getRadius();
};
