#pragma once
#include "nlohmann/json.hpp"
#include "Color.hpp"
#include "Sphere.hpp"

class Scene
{
public:
    Scene() : backgroundColor(), resX(0), resY(0) {}

    Scene(Color backgroundColor, int resX, int resY)
        : backgroundColor(backgroundColor), resX(resX), resY(resY) {}
    
    void addShape(Sphere &shape);

    Color backgroundColor;
    int resX, resY;
    
private:
    std::vector<Sphere> m_spheres;

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Scene, r, g, b, resX, resY);