//
// Created by apgra on 1/11/2024.
//

#ifndef REVOLUTION_3D_RENDERERTEST_H
#define REVOLUTION_3D_RENDERERTEST_H


#include "Scene.h"

namespace R3D {
    class RendererTest : public Scene {
    public:
        RendererTest();
        ~RendererTest();

        void Load() override;

    private:
        void ProcessInput() override;
        void Update() override;
        void Render() override;
        void RenderImGui() override;
    };
}


#endif //REVOLUTION_3D_RENDERERTEST_H
