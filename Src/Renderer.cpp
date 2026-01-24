#include "../include/Renderer.hpp"
#include <iostream>
#include "../include/Ray.hpp"

void Renderer::render() const {
    int width = viewport.resX;
    int height = viewport.resY;


    Point3 camera_origin = {0, 0, 0};

    float aspect_ratio = static_cast<float>(viewport.resX) / viewport.resY;
    float viewport_height = 2.0f;
    float viewport_width = viewport_height * aspect_ratio;
    float focal_length = 1;

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            // Mapowanie pikseli (i, j) na współrzędne 3D (-1 do 1)
            float u = (float(i) / (width - 1) - 0.5f) * viewport_width;
            float v = (0.5f - float(j) / (height - 1)) * viewport_height;

            Ray r = { camera_origin, {u, v, -focal_length} };
            for(const auto& sphere : scene.spheres)
            {
                if (sphere.hit(r)) {
                    // Kolor kuli z JSON
                    std::cout << (int)sphere.color.r << ' ' 
                            << (int)sphere.color.g << ' ' 
                            << (int)sphere.color.b << '\n';
                } else {
                    // Kolor tła z JSON
                    std::cout << (int)scene.backgroundColor.r << ' ' 
                            << (int)scene.backgroundColor.g << ' ' 
                            << (int)scene.backgroundColor.b << '\n';
                }
            }
        }
    }
}