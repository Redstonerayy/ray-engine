#include "engine.hpp"

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Engine::Application* Engine::CreateApplication()
{
    ENGINE_ERROR("SDF");
	return new Sandbox();
}
