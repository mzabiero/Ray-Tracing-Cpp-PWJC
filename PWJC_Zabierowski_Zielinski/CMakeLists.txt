cmake_minimum_required(VERSION 3.10)

project(RayTracer_PWJC VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Src/main.cpp
    Src/camera.cpp
    Src/color.cpp
    Src/hittable_list.cpp
    Src/material.cpp
    Src/sphere.cpp
    Src/vec3.cpp  
)

add_executable(RayTracerApp ${SOURCES})

target_include_directories(RayTracerApp PRIVATE 
    Inc     
    nlohmann       
)