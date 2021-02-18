#pragma once
#include "Core.h"

namespace Oszi {
	class OSZI_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
