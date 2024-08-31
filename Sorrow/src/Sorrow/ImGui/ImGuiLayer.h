#pragma once

#include"Sorrow/Layer.h"


namespace Sorrow {
	class SORROW_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();



	private:


	private:
		float m_Time = 0.0f;
	};
}