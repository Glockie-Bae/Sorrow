#pragma once

#include"Sorrow/Core.h"

namespace Sorrow {
	class SORROW_API Input {

	public:
		// 根据每个平台实现的 IsKeyPressedImpl 来判断是否按下某个键
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

		static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		// 纯虚函数 每个平台都必须实现
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		
	private:
		// 单例对象
		static Input* s_Instance;
	};
}