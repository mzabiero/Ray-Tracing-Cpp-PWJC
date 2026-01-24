#pragma once
#include "Scene.hpp"
#include <iostream>

class Renderer {
public:
    
    Renderer(const Scene& scene);

    void render() const;

private:
    const Scene& scene;
};
