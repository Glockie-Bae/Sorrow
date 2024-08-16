#include"swpch.h"
#include "Application.h"

#include"Sorrow/Events/ApplicationEvent.h"
#include"Sorrow/Log.h"

#include<iostream>
namespace Sorrow {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SW_Client_TRACE(e);

		while (true)
		{
		}
	}

	

}

