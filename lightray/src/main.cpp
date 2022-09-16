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
    Engine::Log::Init();
    Engine::Log::GetEngineLogger()->error("SDF");
	return new Sandbox();
}
