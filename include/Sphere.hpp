#pragma once
#include "Point3.hpp"

class Sphere
{
public:
    Sphere() : origin(0.0, 0.0, 0.0), diameter(1.0) {}
    Sphere(Point3 origin, float diameter)
        : origin(origin), diameter(diameter) {}
        
    float diameter;
    Point3 origin;
private:

};