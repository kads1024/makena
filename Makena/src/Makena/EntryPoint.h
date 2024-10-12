#pragma once
#ifdef MKN_PLATFORM_WINDOWS

// To be implemented in some client...
extern Makena::Application* Makena::CreateApplication();

int main(int argc, char** argv)
{
	printf("Makena...");
	auto app = Makena::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // MKN_PLATFORM_WINDOWS
