#pragma once
#include "Scene.hpp"
#include "Viewport.hpp"
#include "nlohmann/json.hpp"

class Renderer {
public:
    
    Renderer(const Scene& scene, const Viewport& viewport)
        : scene(scene), viewport(viewport) {}

    void render() const;

private:
    const Scene& scene;
    const Viewport &viewport;
};  
