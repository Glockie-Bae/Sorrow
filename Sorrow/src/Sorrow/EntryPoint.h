#pragma once
#include"Application.h"


#ifdef  SORROW_PLATFORM_WINDOWS
extern Sorrow::Application* Sorrow::CreateApplication();

int main(int argc, char** argv) {
	Sorrow::Log::Init();
	SW_CORE_INFO("Initialized Log");
	SW_Client_TRACE("Hello");

	std::cout << "Start Engine!" << std::endl;
	auto app = Sorrow::CreateApplication();
	app->Run();
	delete app;
}

#endif //  SORROW_PLATFORM_WINDOWS
