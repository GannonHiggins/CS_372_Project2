#include "header/basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>

#define M_PI 3.14159265358979323846

using std::string;
using std::stringstream;

Circle::Circle(const double &radius): _radius(radius){

    // if (abs(radius) > this.getWidth())
    //     printf("ERROR --> (Circle) invalid radius: %d\n", radius);
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

Polygon::Polygon(const int numSides, const double sideLength): _numSides(numSides), _sideLength(sideLength){
    double height = .0;
    double width  = .0;

    if (numSides % 2 == 1){
        height = sideLength * (1 + cos(M_PI / numSides)) / (2 * sin(M_PI / numSides));
        width = (sideLength * sin(M_PI * (numSides - 1) / 2 * numSides)) / (sin(M_PI / numSides));
    }
    else if (numSides % 4 == 0){
        height = sideLength * (cos(M_PI / numSides)) / (sin(M_PI / numSides));
        width = (sideLength * cos(M_PI / numSides)) / (sin(M_PI / numSides));
    }
    else{
        height = sideLength * (cos(M_PI / numSides)) / (sin(M_PI / numSides));
        width = sideLength / (sin(M_PI / numSides));
    }

    setHeight(height);
    setWidth(width);
}

void Polygon::draw(std::ostream file) const{
   stringstream out;


}
