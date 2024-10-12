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
int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
	return 0;
}