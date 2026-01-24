#pragma once
#include "Point3.hpp"
#include "Color.hpp"

class Sphere
{
public:
    Sphere() : origin(0.0, 0.0, 0.0), diameter(1.0), color(0,0,0) {}
    Sphere(Point3 origin, float diameter, Color color)
        : origin(origin), diameter(diameter), color(color) {}
        
    float diameter;
    Point3 origin;
    Color color;

private:

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Sphere, diameter, origin, color);