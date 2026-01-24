#include "../include/Renderer.hpp"


Renderer::Renderer(const Scene& scene)
    : scene(scene) {}

void Renderer::render() const {
    int image_width = scene.resX;
    int image_height = scene.resY;

    int r = scene.r;
    int g = scene.g;
    int b = scene.b;

    // Nagłówek PPM
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " 
                  << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            std::cout << r << ' ' << g << ' ' << b << '\n';
        }
    }

    std::clog << "\rDone.                 \n";
}
