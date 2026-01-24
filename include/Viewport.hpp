#pragma once
#include "nlohmann/json.hpp"

struct Viewport
{
    int resX, resY;
    Viewport() : resX(256), resY(256) {};
    Viewport(int resX, int resY) 
        : resX(resX), resY(resY) {};


};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Viewport, resX, resY);

