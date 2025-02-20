#pragma once
#ifdef  CZ_PLATFORM_WINDOWS

extern Cazel::Application* Cazel::CreateApplication();

int main(int argc, char** argv)
{
	Cazel::Log::Init();
	CZ_CORE_WARN("Initialized Log!");

	int a = 5;
	CZ_CLIENT_INFO("Hello! Var = {0}", a);

	auto app = Cazel::CreateApplication();
	app->run();
	delete app;
}
#endif //  CZ_PLATFORM_WINDOWS