cmake_minimum_required(VERSION 3.26)
project(Revolution_3D)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Engine)

include_directories(Engine)

add_executable(Revolution_3D
        main.cpp
)

target_link_libraries(Revolution_3D PRIVATE
    Engine
)