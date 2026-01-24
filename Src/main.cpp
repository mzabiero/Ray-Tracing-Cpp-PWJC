#include <iostream>
#include "../include/nlohmann/json.hpp"
#include "../include/readConfig.hpp"
#include "../include/Scene.hpp"
#include "../include/Renderer.hpp"
#include "../include/Config.hpp"

int main() {

    // Image

    /*
    auto data = readConfig("config.json");
    
    Scene scene = data.scene;
    scene.color;
    Sphere sphere1 = data.sphere;

    

    Renderer::Render(Scene &scene);


    createImage();
    */

    Config config = readConfig("config.json");
    Scene scene = config.scene;
    Viewport viewport = config.viewport;

    Renderer renderer(scene,viewport);

    renderer.render();


    // std::cout << "Sphere color: " << scene.m_sphere.diameter << std::endl;
}