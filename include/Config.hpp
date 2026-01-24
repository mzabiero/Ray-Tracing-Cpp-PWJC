#pragma once
#include "nlohmann/json.hpp"
#include "Scene.hpp"
#include "Color.hpp"
#include "Point3.hpp"
#include "Viewport.hpp"


struct Config
{
    Config() = default;
    Scene scene;
    Viewport viewport;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Config, scene, viewport);