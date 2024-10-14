#pragma once

#include "Core.h"

#include "Window.h"
#include "Makena/LayerStack.h"
#include "Makena/Events/Event.h"
#include "Makena/Events/ApplicationEvent.h"



namespace Makena
{
	class MAKENA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in some client...
	Application* CreateApplication();
}

