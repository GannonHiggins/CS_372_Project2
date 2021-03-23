#pragma once
//#ifndef BASIC_SHAPES_HPP
//#define BASIC_SHAPES_HPP

#include <fstream>

#include "shape.hpp"

//Child classes
class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(prims::position pos, double radius);
    void draw(std::ostream &file);
};

class Polygon : public Shape
{
private:
    int _numSides;
    double _sideLength;

public:
    Polygon::Polygon(prims::position pos, int numof_sides, double lengthof_sides);
    void draw(std::ostream &file);
};