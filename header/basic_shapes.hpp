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
    Circle(const double &radius);

    void draw(std::ostream &file) const;
};

class Poly : public Shape
{
private:
    int _numSides;
    double _sideLength;

public:
    Poly(const int &numSides, const double &sideLength);

    void draw(std::ostream &file) const;
};
