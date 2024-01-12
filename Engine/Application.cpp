//
// Created by apgra on 1/10/2024.
//

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define SCR_TITLE "Revolution 3D"


//STD
#include <cassert>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include "Application.h"
#include "RendererTest.h"


using namespace R3D;


Application::Application() {

}

Application::~Application() {

}

int Application::Run() {
    mRunning = true;

    int exitCode = 0;


    InitRenderer();
    SetupImGui();

    exitCode = GameLoop();
    Cleanup();

    mRunning = false;


    return exitCode;
}

int Application::GameLoop() {
    Scene* curScene = nullptr;
    HomeScene* homeScene = new HomeScene(curScene);
    curScene = homeScene;

    homeScene->RegisterScene<RendererTest>("Renderer Test");


    while(IsRunning() && !WindowShouldClose()){
        curScene->ProcessInput();

        curScene->Update();
        curScene->Render();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Scene");

        if(curScene != homeScene && ImGui::Button("<-")){
            delete curScene;
            curScene = homeScene;
        }

        curScene->RenderImGui();

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }

    return 0;
}

void Application::InitRenderer() {
    //INIT GLFW
    glfwInit();

#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, nullptr, nullptr);

    assert(mWindow != nullptr && "Failed to create GLFW window");

    glfwMakeContextCurrent(mWindow);

    //Init GLAD
    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) && "Failed to initialize GLAD");

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing
}

void Application::Cleanup() {
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

bool Application::IsRunning() const {
    return mRunning;
}

bool Application::WindowShouldClose() {
    return glfwWindowShouldClose(mWindow);
}

void Application::SetupImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    const char* glsl_version = "#version 460";
    ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}


