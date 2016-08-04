#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape
{
    public:
        virtual void setX(int xcor)=0;
        virtual void setY(int ycor)=0;
        virtual int getX() const=0;
        virtual int getY() const=0;
        virtual void draw() const=0;
    protected:
    private:
};

class Circle : public Shape{
    public:
        Circle(int xcor, int ycor, int r);
        virtual void setX(int xcor);
        virtual void setY(int ycor);
        virtual int getX() const;
        virtual int getY() const;
        virtual void draw()const;
        virtual int getRadius()const;
    private:
        int x;
        int y;
        int radius;
};

#endif // SHAPE_H
