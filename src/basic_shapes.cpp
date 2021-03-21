#include "header/basic_shapes.hpp"
#include <sstream>
#include <string>
#include <cmath>

static prims::bounding_box computeBoundingBox(double numof_sides, double lengthof_sides);

Circle::Circle(prims::position pos, double radius)
    : _radius(radius), Shape(pos, {radius, radius}) { }

void Circle::draw()
{
    
}

Polygon::Polygon(prims::position pos, int numof_sides, double lengthof_sides)
    : _numSides(numof_sides), _sideLength(lengthof_sides), Shape(pos, computeBoundingBox(numof_sides, lengthof_sides)) { }

static prims::bounding_box computeBoundingBox(double numof_sides, double lengthof_sides)
{
    prims::bounding_box new_bb;

    if ((int)numof_sides % 2 == 1)
    {
        new_bb.height   = lengthof_sides * (1 + cos(prims::PI / numof_sides)) / (2 * sin(prims::PI / numof_sides));
        new_bb.width    = (lengthof_sides * sin(prims::PI * (numof_sides - 1) / 2 * numof_sides)) / (sin(prims::PI / numof_sides));
    }
    else if ((int)numof_sides % 4 == 0)
    {
        new_bb.height   = lengthof_sides * (cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
        new_bb.width    = (lengthof_sides * cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
    }
    else
    {
        new_bb.height   = lengthof_sides * (cos(prims::PI / numof_sides)) / (sin(prims::PI / numof_sides));
        new_bb.width    = lengthof_sides / (sin(prims::PI / numof_sides));
    }

    return new_bb;
}