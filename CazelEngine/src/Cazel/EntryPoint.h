#pragma once
#ifdef  CZ_PLATFORM_WINDOWS
extern Cazel::Application* Cazel::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cazel::CreateApplication();
	app->run();
	delete app;

	return 0;
}
#endif //  CZ_PLATFORM_WINDOWS