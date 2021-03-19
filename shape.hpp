#ifndef
#define SHAPE_HPP
#include <fstream>


class Shape{
private:
double _height = 0;
double _width = 0;



public:
double getHeight() const;
double getWidth() const;
void setHeight(const double &height);
void setWidth(const double &Width);

void draw(std::ostream &file);
~Shape() = default;


}

#endif