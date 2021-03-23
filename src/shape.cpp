#include "../header/shape.hpp"

Shape::Shape(prims::position _pos, prims::bounding_box bb)
    : _pos(_pos), _bounding_box(bb) { }

prims::position Shape::get_position() { return this->_pos; }
prims::bounding_box Shape::get_boundingBox() { return this->_bounding_box; }

void Shape::set_position(prims::position new_pos) { this->_pos = new_pos; }
void Shape::set_boundingBox(prims::bounding_box new_bb) {this->_bounding_box = new_bb; }