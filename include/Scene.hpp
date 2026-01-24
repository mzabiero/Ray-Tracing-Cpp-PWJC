#pragma once
#include "nlohmann/json.hpp"

class Scene
{
public:
    Scene() : r(0), g(0), b(0), resX(0), resY(0) {}

    Scene(int r, int g, int b, int resX, int resY)
        : r(r), g(g), b(b), resX(resX), resY(resY) {}
    
    int r, g, b;
    int resX, resY;
private:

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Scene, r, g, b, resX, resY);