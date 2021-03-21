#include "shape.hpp"

Shape::Shape(prims::position pos, prims::bounding_box bounding_box)
    : _pos(pos), _bounding_box(bounding_box) { }

prims::position Shape::getPosition()
{
    return this->_pos;
}

prims::bounding_box Shape::getBoundingBox()
{
    return this->_bounding_box;
}

void Shape::setPosition(prims::position new_pos)
{
    this->_pos = new_pos;
}

void Shape::setBoundingBox(prims::bounding_box new_bb)
{
    this->_bounding_box = new_bb;
}