#pragma once

#include"Sorrow/Core.h"

namespace Sorrow {
	class SORROW_API Input {

	public:
		// ����ÿ��ƽ̨ʵ�ֵ� IsKeyPressedImpl ���ж��Ƿ���ĳ����
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

		static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		// ���麯�� ÿ��ƽ̨������ʵ��
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		
	private:
		// ��������
		static Input* s_Instance;
	};
}