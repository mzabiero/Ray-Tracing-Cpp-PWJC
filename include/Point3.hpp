#pragma once
#include <cmath>
#include "nlohmann/json.hpp"

struct Point3
{
    float x,y,z;

    Point3() : x(0), y(0), z(0) {}
    Point3(float x, float y, float z) 
        : x(x), y(y), z(z) {}

    // Operator odejmowania (Punkt - Punkt = Wektor)    
    Point3 operator-(const Point3& v) const {
        return {x - v.x, y - v.y, z - v.z};
    }

    // Operator dodawania (Punkt + Wektor = Punkt)
    Point3 operator+(const Point3& v) const {
        return {x + v.x, y + v.y, z + v.z};
    }

    // Mnożenie przez liczbę (Skalowanie wektora)
    Point3 operator*(float t) const {
        return {x * t, y * t, z * t};
    }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Point3, x, y, z);

// Iloczyn skalarny (Dot Product): zwraca liczbę
inline float dot(const Point3& v1, const Point3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Iloczyn wektorowy (Cross Product): zwraca wektor prostopadły
inline Point3 cross(const Point3& v1, const Point3& v2) {
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

// Długość wektora i normalizacja (bardzo ważne!)
inline float length(const Point3& v) {
    return std::sqrt(dot(v, v));
}

inline Point3 unit_vector(Point3 v) {
    return v * (1.0f / length(v));
}
