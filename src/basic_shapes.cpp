#include "../header/basic_shapes.hpp"
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
    setPosY(.0);
    setPosX(.0);
}


Circle::Circle(const double &posX, const double &posY, const double &radius): _x(posX), _y(posY), _radius(radius){
 setHeight(radius*2);
 setWidth(radius*2);
 setPosX(_x);
 setPosY(_y);
}

void Circle::draw(std::ostream &file) const{
    stringstream out;
    int x = (int)round(_x); 
    int y = (int)round(_y); 
    out <<"gsave\nnewpath\n"
        << x << " "<< y << " " << _radius << " 0 360 arc \nstroke\ngrestore\n";

    file << out.rdbuf();
}

Poly::Poly(const int &numSides, const double &sideLength): _numSides(numSides), _sideLength(sideLength){
    double height = .0;
    double width  = .0;

    if (numSides % 2 == 1){
        height = sideLength * (1 + cos(M_PI / numSides)) / (2 * sin(M_PI / numSides));
        width = (sideLength * sin(M_PI * (numSides - 1) / 2 * numSides)) / (sin(M_PI / numSides));
    }
    else if (numSides % 4 == 0){
        height = sideLength * (cos(M_PI / numSides)) / (sin(M_PI / numSides));
        width = (sideLength * (cos(M_PI / numSides)) / (sin(M_PI / numSides)));
    }
    else{
        height = sideLength * (cos(M_PI / numSides)) / (sin(M_PI / numSides));
        width = sideLength / (sin(M_PI / numSides));
    }

    setHeight(height);
    setWidth(width);
}

void Poly::draw(std::ostream &file) const{
   
   stringstream out;

    out << "gsave\nnewpath\n"
         << "/S " << _numSides << " def /H " << getHeight() / 2 << " \ndef"
         << " /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate "
            "-90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 "
            "S div add def } repeat\n"
         << "closepath\nstroke\ngrestore\n";

    file << out.rdbuf();
}


void Spacer::draw(std::ostream &file)const{
    stringstream out;
    out<<"";
    file << out.rdbuf();
}
