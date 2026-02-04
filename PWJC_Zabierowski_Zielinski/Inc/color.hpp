#pragma once

#include "vec3.hpp"
#include "interval.hpp" 
#include <iostream>

using color = vec3;

double linear_to_gamma(double linear_component);
void write_color(std::ostream& out, const color& pixel_color);