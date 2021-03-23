#include "header/basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>

static prims::bounding_box computeBoundingBox(double numof_sides, double sideLength);

Circle::Circle(prims::position pos, double radius)
    : _radius(radius), Shape(pos, {radius, radius}) { }

void Circle::draw(std::ostream &file)
{
    std::stringstream out;
    prims::position p           = this->getPosition();

    out << "gsave\n"    // Save the stack state
        << (int)p.x << " " << (int)p.y << " moveto\n"   // Move to the shape's position
        << "newpath\n"  // Begin a new path
        << (int)p.x << " " << (int)p.y << " " << _radius << " 0 360 arc\n"  //Path the circle
        << "stroke\n"   // Draw the circle
        << "grestore\n";    // Restore stack state

        file << out.rdbuf();
}

Polygon::Polygon(prims::position pos, int numof_sides, double sideLength)
    : _numSides(numof_sides), _sideLength(sideLength), Shape(pos, computeBoundingBox(numof_sides, sideLength)) { }

void Polygon::draw(std::ostream &file)
{
    std::stringstream out;
    prims::position p           = this->getPosition();

    out << "gsave\n"    // Save the stack state
        << (int)p.x << " " << (int)p.y << " moveto\n"   // Move to the shape's position
        << "newpath\n"  // Begin a new path
        << (int)p.x << " " << (int)p.y << " " << _radius << " 0 360 arc\n"  //Path the circle
        << "stroke\n"   // Draw the circle
        << "grestore\n";    // Restore stack state

        file << out.rdbuf();
}
static prims::bounding_box computeBoundingBox(double numof_sides, double sideLength)
{
    prims::bounding_box new_bb;

    if ((int)numof_sides % 2 == 1)
    {
        new_bb.height   = sideLength * (1 + cos(prims::PI / numof_sides)) / (2 * sin(prims::PI / numof_sides));
        new_bb.width    = (sideLength * sin(prims::PI * (numof_sides - 1) / 2 * numof_sides)) / (sin(prims::PI / numof_sides));
    }
    else if ((int)numof_sides % 4 == 0)
    {
        new_bb.height   = sideLength * (cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
        new_bb.width    = (sideLength * cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
    }
    else
    {
        new_bb.height   = sideLength * (cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
        new_bb.width    = sideLength / (sin(prims::PI / numof_sides));
    }

    return new_bb;
}