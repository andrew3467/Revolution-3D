//
// Created by apgra on 1/10/2024.
//

#ifndef REVOLUTION_3D_APPLICATION_H
#define REVOLUTION_3D_APPLICATION_H

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

        void GameLoop();
        void Cleanup();
        void Render();

        void ProcessInput();


    private:
        bool mRunning = false;

        GLFWwindow* mWindow;
    };
}


#endif //REVOLUTION_3D_APPLICATION_H
