#pragma once
#include"Application.h"


#ifdef  SORROW_PLATFORM_WINDOWS
extern Sorrow::Application* Sorrow::CreateApplication();

int main(int argc, char** argv) {
	std::cout << "Start Engine!" << std::endl;
	auto app = Sorrow::CreateApplication();
	app->Run();
	delete app;
}

#endif //  SORROW_PLATFORM_WINDOWS
