#pragma once
#include"Core.h"
#include"Events/Event.h"

namespace Sorrow {

	class SORROW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}