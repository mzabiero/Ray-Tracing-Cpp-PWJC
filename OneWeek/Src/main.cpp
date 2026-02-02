#include "utility.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "material.hpp"

#include <omp.h>



int main() {
    hittable_list world;

/*     auto material_ground = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = std::make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));
 */
    auto material_ground = std::make_shared<lambertian>(color(0.0, 0.0, 0.0));
    auto material_sphere1 = std::make_shared<lambertian>(color(1.0,1.0,0.0));
    auto material_sphere2 = std::make_shared<metal>(color(0.5,1.0,1.0), 0.1);

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_sphere1));
    world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_sphere2));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 1000;
    cam.samples_per_pixel = 10;
    cam.max_depth         = 10;
    cam.render(world);
}
