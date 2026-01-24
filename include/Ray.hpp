#pragma once
#include "Point3.hpp"

using Vec3 = Point3;
struct Ray
{
    Point3 origin;
    Vec3 direction;

    Ray() = default;
    Point3 at(float t);
    float dot();
};
