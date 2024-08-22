#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Sorrow/Events/ApplicationEvent.h"
#include"Window.h"


namespace Sorrow {

	class SORROW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();

	bool m_Running = true;

}