#include"Sorrow.h"



class Sandbox :public Sorrow::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Sorrow::Application* Sorrow::CreateApplication() {
	return new Sandbox();
}