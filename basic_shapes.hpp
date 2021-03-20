#ifndef BASIC_SHAPES_HPP
#define BASIC_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

//Child classes

class Circle: public Shape{
private:
double _radius;

public: 

Circle(const double &radius);

void draw(std::ostream &file) const;

};

class Polygon: public Shape {
private:
    int _numSides; 
    double _sideLength;
public: 

Polygon(const int &numSides, const double &SideLength );
void draw(std::ostream &file) const;

}
#endif
