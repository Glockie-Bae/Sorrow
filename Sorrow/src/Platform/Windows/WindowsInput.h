#pragma once
#include"Sorrow/Input.h"

namespace Sorrow {
	class WindowInput : public Input {

	public:
		// 按键是否按下
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;

		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}