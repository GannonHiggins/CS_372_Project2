#pragma once

#include <array>
#include <vector>
#include "shape.hpp"
#include "basic_shapes.hpp"
#include "primatives.hpp"

class ShapeContainer
{
private:
    prims::position _pos;
    std::vector<Shape> _shapes;

public:
    ShapeContainer(prims::position pos);

    //void move(Shape a, bool verticale, double movedSpace);

    //void layered(Shape a, std::vector<Shape> vec);

   // void Scaled(double x, double y, Shape buf);  

    ~ShapeContainer() = default;
};
