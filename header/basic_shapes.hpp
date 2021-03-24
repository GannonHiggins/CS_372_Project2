#pragma once

#include "shape.hpp"
#include <fstream>

//Child classes
class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(prims::position pos, double radius);

    void draw(std::string file);
};

class Poly : public Shape
{
private:
    int _numSides;
    double _sideLength;
    double _rotatation = 0;

public:
    Poly(prims::position pos, int numSides, double sideLength);
    
    void rotate(double degrees);

   void draw(std::string file);
};


class Square: public Poly
{
public:
    Square(prims::position pos, double length)
        : Poly(pos, 4, length) { }
};


class Triangle: public Poly
{
public: 
    Triangle(prims::position pos, double length)
        : Poly(pos, 3, length) { }
};


class Rect: public Shape {
private:
    double _width;
    double _height;
    double _rotation; 
public: 

    Rect(prims::position pos, double width, double height);

    void rotate(double rotation);

    void draw(std::string file);;
};


class Spacer: public Shape
{
public: 
    Spacer(prims::position pos, double width, double height)
        : Shape(pos, {width, height}) { }

    void draw(std::string file);

};

void Move(Rect a, bool verticle, double movedSpace);