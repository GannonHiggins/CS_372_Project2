#include "../header/basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using std::string;
using std::stringstream;

static prims::bounding_box compute_boundingBox(int numSides, int numLength);

Circle::Circle(prims::position pos, double radius) 
    : _radius(radius), Shape(pos, {radius * 2, radius * 2}) { }

void Circle::draw(std::string file) {
    stringstream out;
    std::ofstream of;

    prims::position p = this->get_position();
    of.open(file);
    of <<"gsave\nnewpath\n"
        << p.x << " "<< p.y << " " << _radius << " 0 360 arc \nstroke\ngrestore\nshowpage";
    
    of.close();
}

Poly::Poly(prims::position pos, int numSides, double sideLength)
    : _numSides(numSides), _sideLength(sideLength), Shape(pos, compute_boundingBox(numSides, sideLength)) {
        if(numSides == 4){
            _rotatation+=45;
        }
        else if(numSides == 3){
            _rotatation-=30;
    }
 }


void Poly::rotate(double degrees){
    _rotatation = degrees;
}

void Poly::draw(std::string file){

   std::ofstream output;
   output.open(file);
    prims::position p = this->get_position();

    if (_numSides < 5)
        _rotatation += 45;

    output <<"gsave\n"<< p.x << " "<< p.y<< " translate\n" << _rotatation << " rotate\n/S " << _numSides << " def\n/H " 
    << this->get_boundingBox().height/2 <<" def\nnewpath\nH 0 moveto\n1 1 S 1 sub\n"
    <<"{\n /i exch def\n 360 S div i mul cos H mul\n 360 S div i mul sin H mul lineto\n} for\n"
    <<"closepath\nstroke\ngrestore\nshowpage";
    output.close();

  

}

Rect::Rect(prims::position pos, double width, double height)
        : Shape(pos, {width, height}), _width(width), _height(height) { }


void Rect::rotate(double rotation){
    _rotation = rotation;
}

void Rect::draw(std::string file){
    prims::position p = this->get_position();
    std::ofstream output;
    output.open(file);

    output<< "gsave\nnewpath\n"<< p.x << " "<< p.y << " moveto\n" << _rotation << " rotate\n0 "<< _height << " rlineto\n"
   <<_width << " 0 rlineto\n"<< "0 -" << _height << " rlineto\n" << "-" << _width << " 0 rlineto\nclosepath\nstroke\n" <<
   "grestore\nshowpage";
    output.close();

}




void Spacer::draw(std::string file) {
    std::ofstream of;
    of.open(file);
    of<<"";
    of.close();
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