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
    //std::array<Shape> _shapes;
public:
    ShapeContainer(prims::position pos );

    void move(Rect a, bool verticale, double movedSpace);

    ~ShapeContainer() = default;
};
