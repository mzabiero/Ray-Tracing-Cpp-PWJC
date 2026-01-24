
#pragma once
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Config.hpp"

inline Config readConfig(const std::string& fname)
{

    std::ifstream file(fname); 
    
    if (!file.is_open()) {

        std::cerr << "Nie udalo sie otworzyc pliku config.json! Zwracam domyslna scene." << std::endl;
        return Config(); 
    }

    nlohmann::json j;
    file >> j;

    return j.get<Config>();
}