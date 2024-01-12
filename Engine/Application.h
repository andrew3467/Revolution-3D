//
// Created by apgra on 1/10/2024.
//

#ifndef REVOLUTION_3D_APPLICATION_H
#define REVOLUTION_3D_APPLICATION_H

//STD
#include <vector>

#include "Scene.h"

struct GLFWwindow;

namespace R3D {
    class Application {
    public:
        Application();

        ~Application();


    public:
        int Run();

        bool IsRunning() const;
        bool WindowShouldClose();

    private:
        void InitRenderer();

        int GameLoop();
        void Cleanup();


    private:
        std::vector<Scene> mScenes;

        bool mRunning = false;

        GLFWwindow* mWindow;

        void SetupImGui();
    };
}


#endif //REVOLUTION_3D_APPLICATION_H
