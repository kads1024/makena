#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Makena
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MKN_TRACE(e);

		while (true);
	}
}
