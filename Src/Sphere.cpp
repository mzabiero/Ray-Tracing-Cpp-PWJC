#include "../include/Sphere.hpp"

bool Sphere::hit(const Ray& r) const {
    Point3 oc = r.origin - origin; 
    
    // a = d · d
    float a = dot(r.direction, r.direction); 
    // b = 2 * oc · d
    float b = 2.0f * dot(oc, r.direction);
    // c = oc · oc - r^2
    float radius = diameter / 2.0f;
    float c = dot(oc, oc) - radius * radius;
    
    float discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}