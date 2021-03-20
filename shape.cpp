#include "shape.hpp"


double Shape::getHeight() const { return _boundingBox.height; }

double Shape::getWidth() const { return _boundingBox.width; }

void Shape::setHeight(const double height) { _boundingBox.height = height; }

void Shape::setWidth(const double width) { _boundingBox.width = width; }

double Shape::getPosX() const { return _position.x; }

double Shape::getPosY() const { return _position.y; }

void Shape::setPosX(const double posX) { _position.x = posX; }

void Shape::setPosY(const double posY) { _position.y = posY; }