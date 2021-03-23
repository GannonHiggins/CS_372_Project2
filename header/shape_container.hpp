#pragma once

#include <array>
#include "shape.hpp"
#include "primatives.hpp"

class ShapeContainer
{
private:
    prims::position _pos;
    std::array<Shape> _shapes;
public:
    ShapeContainer(prims::position pos );
    ~ShapeContainer();

    void rotate();
};
