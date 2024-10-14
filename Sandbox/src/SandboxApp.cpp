#include <Makena.h>

class Sandbox : public Makena::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Makena::Application* Makena::CreateApplication()
{
	return new Sandbox();
}