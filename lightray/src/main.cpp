#include "engine.hpp"

class Lightray : public Engine::Application
{
public:
	Lightray()
	{

	}

	~Lightray()
	{

	}

};

Engine::Application* Engine::CreateApplication()
{
	return new Lightray();
    
}
