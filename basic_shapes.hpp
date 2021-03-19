#ifndef BASIC_SHAPES_HPP
#define BASIC_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

class Circle: public Shape{
private:
double _radius;

public: 
Circle(const double &radius);
void draw(std::ostream &file) const;

};

#endif
