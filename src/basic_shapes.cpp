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
    prims::position p = this->get_position();

    out << p.x << " "<< p.y<< " translate\n/S " << _numSides << " def\n/H " 
    << this->get_boundingBox().height/2 <<" def\nnewpath\nH 0 moveto\n1 1 S 1 sub\n"
    <<"{\n /i exch def\n 360 S div i mul cos H mul\n 360 S div i mul sin H mul lineto\n} for\n"
    <<"closepath\nstroke\nshowpage";

    file << out.rdbuf();
}

Rect::Rect(prims::position pos, double width, double height)
        : Shape(pos, {width, height}), _width(width), _height(height) { }


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

Rect Move(Rect a, bool verticale, double movedSpace){

       /* this should take the position of a Rectangle and add a number
       to the x or y value of its position. thus changeing its position when printed*/

       /* i could not get this to work for the life of me. 
       Also if this could work on all shapes that would save a lot of time*/
};