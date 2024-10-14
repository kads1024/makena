#include "mknpch.h"
#include "Application.h"

#include "Makena/Events/ApplicationEvent.h"
#include "Makena/Log.h"

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
		if (e.IsInCategory(EventCategoryApplication))
		{
			MKN_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MKN_TRACE(e.ToString());
		}

		while (true);
	}
}
