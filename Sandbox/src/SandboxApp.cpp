#include <Cazel.h>

class Sandbox : public Cazel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Cazel::Application* Cazel::CreateApplication()
{
	return new Sandbox();
}