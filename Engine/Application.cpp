//
// Created by apgra on 1/10/2024.
//

#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define SCR_TITLE "Revolution 3D"


//STD
#include <cassert>

#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>




using namespace R3D;


Application::Application() {

}

Application::~Application() {

}

int Application::Run() {
    mRunning = true;

    InitRenderer();

    GameLoop();
    Cleanup();

    mRunning = false;


    return 1;
}

void Application::GameLoop() {
    while(IsRunning() && !WindowShouldClose()){
        ProcessInput();



        Render();

        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
}

void Application::Render() {

}

void Application::ProcessInput() {
    if(glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(mWindow, true);
    }

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



