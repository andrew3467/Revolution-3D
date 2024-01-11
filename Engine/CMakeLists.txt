cmake_minimum_required(VERSION 3.26)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_library(Engine
        Application.cpp
        Application.h
        Scene.cpp
        Scene.h)

target_link_libraries(Engine PRIVATE
        glfw
        glad::glad
)