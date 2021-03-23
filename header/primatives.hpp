#pragma once

namespace prims 
{
    const double PI = 3.14159265358979323846;

    enum UNITS
    {
        INCH = 1 / 72
    };

    struct bounding_box
    { 
        double width = .0, height = .0;
    };

    struct position
    {
        double x = .0, y = .0; 
    };

    struct scale
    {
        double x = .0, y = .0;
    };
    
    union rotation
    {
        double radians;
        double degrees;
    };
}
