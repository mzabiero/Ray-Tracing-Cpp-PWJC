#include <iostream>
#include "../include/nlohmann/json.hpp"
#include "../include/readConfig.hpp"
#include "../include/Scene.hpp"


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

    Scene scene = readConfig("config.json");
    

    int image_width = scene.resX;
    int image_height = scene.resY;
    auto r = scene.r;
    auto g = scene.g;
    auto b = scene.b;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            std::cout << r << ' ' << g << ' ' << b << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}