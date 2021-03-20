#include "basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>


using std::string;
using std::stringstream;

Circle::Circle(const double &radius): _radius(radius){

    setHeight(radius*2);

    setWidth(radius*2);
}

void Circle::draw(std::ostream &file) const{
    stringstream out;

    out <<"gsave\nnewpath\n" 
        <<getHeight()/2.0 << " " << getWidth() / 2.0 << " " << _radius
        <<" 0 360 arc \nstroke\ngrestore\n";

        file << out.rdbuf();
}

void Polygon::draw(std::ostream &file) const{
    
}
