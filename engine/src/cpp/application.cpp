#include "application.hpp"
#include "log.hpp"
#include "applicationevents.h"

#include <iostream>

namespace Engine {
    Application::Application(){
    }

    Application::~Application(){

    }

    void Application::Run(){
        WindowResizeEvent e(1280, 720);
		std::cout << e.ToString() << std::endl;
        std::string error = e.ToString();
        // if (e.IsInCategory(EventCategoryApplication))
		// {
		// 	ENGINE_TRACE(e.ToString());
		// }
		// if (e.IsInCategory(EventCategoryInput))
		// {
		// 	ENGINE_TRACE(e.ToString());
		// }
    }
}
