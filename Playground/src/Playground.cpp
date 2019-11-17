#include <SGEngine.h>
#include <cstdio>
namespace PG
{
	class ExampleLayer : public SGEngine::Layer
	{
		void OnUpdate() override
		{
			SGE_CLIENT_INFO("Layer Updating!");
		}

		void OnEvent(SGEngine::Event& event) override
		{
			SGE_CLIENT_INFO("Layer Event {0}", event);
		}
	};
}
class Playground : public SGEngine::Application
{
public:
	Playground():Application()
	{
		PushLayer(new PG::ExampleLayer());
		SGE_CLIENT_INFO("Hello from the client Side!");
	}
	~Playground()
	{
		
	}
};

SGEngine::Application* SGEngine::CreateApplication()
{
	return new Playground();
}