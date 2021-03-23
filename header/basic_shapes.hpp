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
    double _x;
    double _y;

public:
    Circle(const double &radius);

    Circle(const double &posX, const double &PosY, const double &radius);

    //void draw_pos(std::ostream &file)const;
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


class Square: public Poly
{
public:

Square(const double &length): Poly(4,length){}

};

class Triangle: public Poly
{
public: 

Triangle(const double &length): Poly(3, length){}

};

class Spacer: public Shape
{

private: 
double _height;
double _width;

public: 

Spacer(const double &height, const double &width): _height(height), _width(width){};

void draw(std::ostream &file)const;

};