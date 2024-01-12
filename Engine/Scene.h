//
// Created by apgra on 1/11/2024.
//

#ifndef REVOLUTION_3D_SCENE_H
#define REVOLUTION_3D_SCENE_H

#include <string>
#include <functional>
#include <iostream>

class GLFWwindow;

namespace R3D {
    class Scene {
    public:
        Scene();
        ~Scene();

        virtual void Load();

        bool IsOpen();

        virtual void ProcessInput();
        virtual void Update();
        virtual void Render();
        virtual void RenderImGui();


    protected:
        bool mIsOpen = false;
    };

    class HomeScene : public Scene{
    public:
        HomeScene(Scene*& currentScene) : mCurrentScene(currentScene){}
        ~HomeScene()= default;

        void RenderImGui() override;

        template<typename T>
        void RegisterScene(const std::string &name){
            mScenes.push_back(std::make_pair(name, [](){return new T;}));

            std::cout << "Registered Scene: " << name << std::endl;
        }

    private:
        Scene*& mCurrentScene;
        std::vector<std::pair<std::string, std::function<Scene*()>>> mScenes;
    };
}


#endif //REVOLUTION_3D_SCENE_H
