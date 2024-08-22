#include"swpch.h"
#include "Application.h"

#include"Sorrow/Log.h"
#include"Platform/Windows/WindowsWindow.h"

#include<iostream>
namespace Sorrow {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window.get()->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		SW_CORE_INFO("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{

			glClearColor(1.0, 0.0, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();	
		}
	}

	

}

