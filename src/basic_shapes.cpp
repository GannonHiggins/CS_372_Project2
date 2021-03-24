#include "../header/basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>

using std::string;
using std::stringstream;

static prims::bounding_box compute_boundingBox(int numSides, int numLength);

Circle::Circle(prims::position pos, double radius) 
    : _radius(radius), Shape(pos, {radius * 2, radius * 2}) { }

void Circle::draw(std::ostream &file) {
    stringstream out;
    std::ofstream of;

    prims::position p = this->get_position();

    out <<"gsave\nnewpath\n"
        << p.x << " "<< p.y << " " << _radius << " 0 360 arc \nstroke\ngrestore\n";
    
    file << out.rdbuf();
}

Poly::Poly(prims::position pos, int numSides, double sideLength)
    : _numSides(numSides), _sideLength(sideLength), Shape(pos, compute_boundingBox(numSides, sideLength)) {}


void Poly::draw(std::ostream &file){
   
   stringstream out;

    out << "gsave\nnewpath\n"
         << "/S " << _numSides << " def /H " << this->get_boundingBox().height / 2 << " \ndef"
         << " /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate "
            "-90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 "
            "S div add def } repeat\n"
         << "closepath\nstroke\ngrestore\n";

    file << out.rdbuf();
}

Rect::Rect(prims::position pos, double width, double height)
        : Shape(pos, {width, height}), _width(width), _height(height) { 
            //_width = width;
           //_height = height;
        }


void Rect::draw(std::ostream &file){
    stringstream out;
    
    prims::position p = this->get_position();

    out<< p.x << " " << p.y << " moveto\n" << "gsave\nnewpath\n"
         << "-" << _width / 2.0 << " -" << _height / 2.0 << " "
         <<  _width << " " << _height
         << " rectstroke \nstroke\ngrestore\n";
  file << out.rdbuf();

}


void Spacer::draw(std::ostream &file) {
    stringstream out;
    out<<"";
    file << out.rdbuf();
}

static prims::bounding_box compute_boundingBox(int numSides, int sideLength)
{
    const double PI = 3.14159265358979323846;

    prims::bounding_box ret_bb;
    if (numSides % 2 == 1){
        ret_bb.height   = sideLength * (1 + cos(PI / numSides)) / (2 * sin(PI / numSides));
        ret_bb.width    = (sideLength * sin(PI * (numSides - 1) / 2 * numSides)) / (sin(PI / numSides));
    }
    else if (numSides % 4 == 0){
        ret_bb.height   = sideLength * (cos(PI / numSides)) / (sin(PI / numSides));
        ret_bb.width    = (sideLength * (cos(PI / numSides)) / (sin(PI / numSides)));
    }
    else{
        ret_bb.height   = sideLength * (cos(PI / numSides)) / (sin(PI / numSides));
        ret_bb.width    = sideLength / (sin(PI / numSides));
    }
    return ret_bb;
}