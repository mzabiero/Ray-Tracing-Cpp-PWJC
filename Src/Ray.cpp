#include "../include/Ray.hpp"

Point3 Ray::at(float t)
{
    return 
    {
        origin.x + t * direction.x,
        origin.y + t * direction.y,
        origin.z + t * direction.z
    };
}

float Ray::dot()
{
    return direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
}