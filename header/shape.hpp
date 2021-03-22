#pragma once 

#include <fstream>

//Base Class
class Shape
{
private:
    double _height  = .0;
    double _width   = .0;
     
    double _x = .0;
    double _y = .0;
  
    

public:
    double getHeight() const;
    double getWidth() const;
    void setHeight(const double &height);
    void setWidth(const double &width);

    double getPosX() const;
    double getPosY() const;
    void setPosX(const double posX);
    void setPosY(const double posY);

    virtual void draw(std::ostream &file) const = 0;
    virtual ~Shape() = default;
};
