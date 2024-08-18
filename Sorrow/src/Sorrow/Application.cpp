#include"swpch.h"
#include "Application.h"

#include"Sorrow/Events/ApplicationEvent.h"
#include"Sorrow/Log.h"
#include"Platform/Windows/WindowsWindow.h"

#include<iostream>
namespace Sorrow {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

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

