#pragma once
#include "nlohmann/json.hpp"
#include "Color.hpp"
#include "Sphere.hpp"

class Scene
{
public:
    Scene() : backgroundColor() {}

    Scene(Color backgroundColor)
        : backgroundColor(backgroundColor) {}
    
    // Sphere& getSphere() ;
    // void addShape(Sphere &shape);

    Color backgroundColor;
    std::vector<Sphere> spheres;
private:
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Scene, backgroundColor, spheres);