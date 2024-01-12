cmake_minimum_required(VERSION 3.26)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

include_directories(../Extern/imgui)

set(ImGuiSrc
        ../Extern/imgui/imgui_impl_glfw.h
        ../Extern/imgui/imgui_impl_glfw.cpp
        ../Extern/imgui/imgui_impl_opengl3.h
        ../Extern/imgui/imgui_impl_opengl3.cpp
        ../Extern/imgui/imgui_impl_opengl3_loader.h
)

add_library(Engine
        ${ImGuiSrc}
        Application.cpp
        Application.h
        Scene.cpp
        Scene.h
        RendererTest.cpp
        RendererTest.h
)

target_link_libraries(Engine PRIVATE
        glfw
        glad::glad
        imgui::imgui
        glm::glm
)