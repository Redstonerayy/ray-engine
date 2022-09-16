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
        Log::Init();
        if (e.IsInCategory(EventCategoryApplication))
		{
			ENGINE_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ENGINE_TRACE(e.ToString());
		}
    }
}
