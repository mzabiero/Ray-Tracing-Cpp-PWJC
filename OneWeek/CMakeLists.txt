cmake_minimum_required(VERSION 3.10)

# 1. Nazwa projektu
project(RayTracer_PWJC VERSION 1.0 LANGUAGES CXX)

# 2. Standard C++ (C++17 jest zalecany dla biblioteki nlohmann/json)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Definiujemy pliki źródłowe (tylko .cpp, nagłówki zostaną znalezione automatycznie)
set(SOURCES
    Src/main.cpp
)

# 4. Tworzymy plik wykonywalny
add_executable(RayTracerApp ${SOURCES})

# 5. Includes
target_include_directories(RayTracerApp PRIVATE 
    Inc            
)