#pragma once

#include <array>
#include <vector>
#include "shape.hpp"
#include "primatives.hpp"

class ShapeContainer
{
private:
    prims::position _pos;
    //std::array<Shape> _shapes;
    std::vector<std::pair<prims::position,Shape>> _container;
public:
    ShapeContainer(prims::position pos );
    ~ShapeContainer();

    void rotate();
};
