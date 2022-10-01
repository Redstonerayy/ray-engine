#pragma once

#include "engine.hpp"
#include "event.hpp"
#include "window.hpp"

namespace Engine {
    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };


    // definded in client
    Application* CreateApplication();
}
