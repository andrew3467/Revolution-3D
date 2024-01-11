//STD
#include <new>

#include <Application.h>
#include <cassert>


int main(int argc, char* argv[]) {
    R3D::Application* app;

    app = new(std::nothrow) R3D::Application();
    assert(app != nullptr && "main() Can't create Application");

    int EXIT_CODE = app->Run();

    delete app;
    app = nullptr;

    return EXIT_CODE;
}
