#include <fstream>
#include "json.hpp"
#include "utility.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "material.hpp"

using json = nlohmann::json;

// Pomocnicza funkcja do zamiany tablicy JSON [x,y,z] na vec3
vec3 json_to_vec3(const json& j) {
    return vec3(j[0], j[1], j[2]);
}

// Fabryka materiałów
std::shared_ptr<material> create_material(const json& j_mat) {
    std::string type = j_mat["type"];
    color albedo = json_to_vec3(j_mat["color"]);

    if (type == "lambertian") {
        return std::make_shared<lambertian>(albedo);
    } else if (type == "metal") {
        double fuzz = j_mat.value("fuzz", 0.0); // value() pozwala ustawić domyślną wartość
        return std::make_shared<metal>(albedo, fuzz);
    }
    return nullptr;
}

int main() {
    // 1. Wczytanie pliku JSON
    std::ifstream file("../config.json");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku config.json!" << std::endl;
        return 1;
    }
    json data = json::parse(file);

    // 2. Konfiguracja Świata (World)
    hittable_list world;
    for (const auto& item : data["world"]) {
        if (item["type"] == "sphere") {
            auto center = json_to_vec3(item["center"]);
            auto radius = item["radius"].get<double>();
            auto mat = create_material(item["material"]);
            world.add(std::make_shared<sphere>(center, radius, mat));
        }
    }

    // 3. Konfiguracja Kamery
    camera cam;
    auto j_cam = data["camera"];
    cam.aspect_ratio      = j_cam.value("aspect_ratio", 16.0/9.0);
    cam.image_width       = j_cam.value("image_width", 400);
    cam.samples_per_pixel = j_cam.value("samples_per_pixel", 100);
    cam.max_depth         = j_cam.value("max_depth", 50);

    // 4. Renderowanie
    cam.render(world);

    return 0;
}