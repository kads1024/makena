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
		// MKN_INFO("ExampleLayer::Update");

		if (Makena::Input::IsKeyPressed(MKN_KEY_TAB))
			MKN_TRACE("Tab Key is pressed (poll)!");
	}
	
	void OnEvent(Makena::Event& event) override
	{
		if (event.GetEventType() == Makena::EventType::KeyPressed)
		{
			Makena::KeyPressedEvent& e = (Makena::KeyPressedEvent&)event;
			if (e.GetKeyCode() == MKN_KEY_TAB)
				MKN_TRACE("Tab key is pressed (event)!");
			
			MKN_TRACE((char)e.GetKeyCode());
		}
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