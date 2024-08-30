#include"Sorrow.h"


class ExampleLayer : public Sorrow::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {
		//SW_Client_INFO("ExampleLayer::Update");
		if (Sorrow::Input::IsKeyPressed(SW_KEY_TAB))
			SW_Client_INFO("Tab is pressed!");
	}

	void OnEvent(Sorrow::Event& e) override {
		
		//SW_Client_TRACE("{0}", e);
		if (e.GetEventType() == Sorrow::EventType::KeyPressed) {
			Sorrow::KeyPressedEvent& event = (Sorrow::KeyPressedEvent&)e;
			SW_Client_TRACE("{0}", (char)event.GetKeyCode());
		}
	}
};

class Sandbox :public Sorrow::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Sorrow::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Sorrow::Application* Sorrow::CreateApplication() {
	return new Sandbox();
}
