//
// Created by apgra on 1/11/2024.
//

#include "RendererTest.h"

#include <glad/glad.h>
#include <imgui.h>

struct vec3{
    float x;
    float y;
    float z;
} V;

R3D::RendererTest::RendererTest() {
    Scene::Load();
    Load();
}

R3D::RendererTest::~RendererTest() {

}

void R3D::RendererTest::Load() {

}

void R3D::RendererTest::ProcessInput() {

}

void R3D::RendererTest::Update() {

}

void R3D::RendererTest::Render() {
    glClearColor(V.x, V.y, V.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Scene::Render();
}

void R3D::RendererTest::RenderImGui() {
    Scene::RenderImGui();

    ImGui::ColorPicker3("Color", &V.x);
}
