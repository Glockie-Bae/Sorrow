#pragma once

#include"Sorrow/Core.h"
#include"Sorrow/Events/Event.h"
#include"Sorrow/Events/MouseEvent.h"
#include"Sorrow/Events/KeyEvent.h"
#include"Sorrow/Events/ApplicationEvent.h"


namespace Sorrow
{
	class SORROW_API Layer{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}