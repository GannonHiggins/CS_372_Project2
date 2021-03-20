#pragma once 

#include <fstream>

//Base Class
class Shape
{
private:

    struct boundingBox
    {
        double height  = .0;
        double width   = .0;
    } _boundingBox;    

    struct position
    {
        double x = .0;
        double y = .0;
    } _position;
    

public:
    double getHeight() const;
    double getWidth() const;
    void setHeight(const double height);
    void setWidth(const double width);

    double getPosX() const;
    double getPosY() const;
    void setPosX(const double posX);
    void setPosY(const double posY);

    virtual void draw(std::ostream &file) const = 0;
    virtual ~Shape() = default;
};
