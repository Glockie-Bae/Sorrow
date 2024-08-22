#include"Sorrow.h"


class ExampleLayer : public Sorrow::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {
		SW_Client_INFO("ExampleLayer::Update");
	}

	void OnEvent(Sorrow::Event& e) override {
		SW_Client_TRACE("{0}", e);
	}
};

class Sandbox :public Sorrow::Application {
public:
	Sandbox() {
		PuahLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Sorrow::Application* Sorrow::CreateApplication() {
	return new Sandbox();
}
