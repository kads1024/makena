#include <Makena.h>

class ExampleLayer : public Makena::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		MKN_INFO("ExampleLayer::Update");
	}
	
	void OnEvent(Makena::Event& event) override
	{
		MKN_TRACE(event.ToString());
	}
};

class Sandbox : public Makena::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Makena::Application* Makena::CreateApplication()
{
	return new Sandbox();
}