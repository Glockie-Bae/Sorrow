#pragma once
#include"Application.h"
#include<iostream>

#ifdef  SORROW_PLATFORM_WINDOWS
extern Sorrow::Application* Sorrow::CreateApplication();

int main(int argc, char** argv) {
	Sorrow::Log::Init();
	SW_CORE_INFO("Initialized Log");
	SW_Client_TRACE("Hello");

	auto app = Sorrow::CreateApplication();
	std::cout << "Start Engine!" << std::endl;
	app->Run();
	delete app;
}

#endif //  SORROW_PLATFORM_WINDOWS
