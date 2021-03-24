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
    prims::position get_position();
    prims::bounding_box get_boundingBox();

    void set_position(prims::position new_pos);
    void set_boundingBox(prims::bounding_box new_bb);

    Shape(prims::position pos, prims::bounding_box bb);

    virtual void draw(std::string file)=0;
    virtual ~Shape() = default;
};
