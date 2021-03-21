#pragma once
//#ifndef BASIC_SHAPES_HPP
//#define BASIC_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

//Child classes
class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(prims::position pos, double radius);
    void draw();
};

class Polygon : public Shape
{
private:
    int _numSides;
    double _sideLength;

public:
    Polygon::Polygon(prims::position pos, int numof_sides, double lengthof_sides);
    void draw();
};