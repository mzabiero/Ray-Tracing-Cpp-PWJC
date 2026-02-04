#pragma once

#include "ray.hpp"
#include "color.hpp"
#include "hittable.hpp"

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const;
};

class lambertian : public material {
  public:
    lambertian(const color& albedo);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override;

  private:
    color albedo;
};

class metal : public material {
  public:
    metal(const color& albedo, double fuzz);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override;

  private:
    color albedo;
    double fuzz;
};