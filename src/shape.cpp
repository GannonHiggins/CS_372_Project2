#include "../header/shape.hpp"


double Shape::getHeight() const { return _height; }

double Shape::getWidth() const { return _width; }

void Shape::setHeight(const double &height) { _height = height; }

void Shape::setWidth(const double &width) { _width = width; }

double Shape::getPosX() const { return _x; }

double Shape::getPosY() const { return _y; }

void Shape::setPosX(const double posX) { _x = posX; }

void Shape::setPosY(const double posY) { _y = posY; }
