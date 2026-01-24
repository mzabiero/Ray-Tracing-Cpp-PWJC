#include <iostream>
#include "../include/nlohmann/json.hpp"

int main() {

    // Image

    auto data = readConfig("config.json");
    
    Scene scene = data.scene;
    scene.color;
    Sphere sphere1 = data.sphere;


    Renderer::Render(resX, resY, scene.color);
    createImage();


    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto black = 0;
            std::cout << black << ' ' << black << ' ' << black << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}