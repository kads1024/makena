#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Makena
{
	class MAKENA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
	};

	// To be defined in some client...
	Application* CreateApplication();
}

