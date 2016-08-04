#include <iostream>
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

using namespace std;
// POINT CLASS
class point{
public:
    point(double x=0.0,double y=0.0);
    double getx() const;
    void setx(double v);
    double gety() const;
    void sety(double v);

private:
    double x,y;
};

point operator+(point& p1, point& p2);
ostream& operator<< (ostream& out,const point& p);

#endif // POINT_H_INCLUDED
