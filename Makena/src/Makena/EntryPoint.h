#pragma once
#ifdef MKN_PLATFORM_WINDOWS

// To be implemented in some client...
extern Makena::Application* Makena::CreateApplication();

int main(int argc, char** argv)
{
	Makena::Log::Init();
	MKN_CORE_WARN("Initialized Log!");
	int a = 5;
	MKN_INFO("Hello! Var={0}", a);

	auto app = Makena::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // MKN_PLATFORM_WINDOWS
