//
// Created by apgra on 1/11/2024.
//

#include "Scene.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

namespace R3D {
    Scene::Scene() {

    }

    Scene::~Scene() {

    }

    void Scene::Load() {
        mIsOpen = true;
    }

    void Scene::ProcessInput() {

    }

    void Scene::Update() {

    }

    void Scene::Render() {

    }

    void Scene::RenderImGui() {
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);

    }

    bool Scene::IsOpen() {
        return mIsOpen;
    }

    void HomeScene::RenderImGui() {
        Scene::RenderImGui();
        for(auto& scene : mScenes){
            if(ImGui::Button(scene.first.c_str())){
                mCurrentScene = scene.second();
            }
        }
    }
}
