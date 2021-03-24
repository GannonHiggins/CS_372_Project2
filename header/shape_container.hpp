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

//this should move a Rectangle left x amount of spaces
    void Move(Rect a, bool verticale, double movedSpace){
        if(verticale == false){
       a.get_position();
       _pos.x = _pos.x + movedSpace;
        }
        else{
            _pos.y = _pos.y + movedSpace;
        }
    };

    ~ShapeContainer();

    void rotate();
};
