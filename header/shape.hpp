#pragma once 

#include <fstream>

#include "primatives.hpp"

//Base Class
class Shape
{
private:

    prims::position _pos;
    prims::bounding_box _bounding_box;

public:

    prims::position getPosition();
    prims::bounding_box getBoundingBox();

    void setPosition(prims::position new_pos);
    void setBoundingBox(prims::bounding_box new_bb);

    Shape::Shape(prims::position pos, prims::bounding_box bounding_box);

    virtual void draw() { };
};
