#include <SGEngine.hpp>
#include <cstdio>

class Playground : public SGEngine::Application
{
public:
	Playground():Application()
	{
		
	}
	~Playground()
	{
		
	}
};

SGEngine::Application* SGEngine::CreateApplication()
{
	return new Playground();
}