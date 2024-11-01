#pragma once
#include "Core.h"
namespace Cazel {
	class CAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}


