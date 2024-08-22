#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Sorrow/Events/ApplicationEvent.h"
#include"Window.h"

#include"Sorrow/LayerStack.h"


namespace Sorrow {

	class SORROW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PuahLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();


}