#include <SGEngine.h>
#include <cstdio>

class Playground : public SGEngine::Application
{
public:
	Playground():Application()
	{
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