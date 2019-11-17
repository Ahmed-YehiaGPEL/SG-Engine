#pragma once
#include "Event.h"

namespace SGEngine
{
	class MouseButtonEvent :public Event {
	public:
		int GetMouseButtonCode() const { return mMouseButtonCode; }
	protected:
		MouseButtonEvent(const int mouseButtonCode)
			: mMouseButtonCode(mouseButtonCode) {
		}
	private:
		int mMouseButtonCode;
	};

	class MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode) {
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed: " << GetMouseButtonCode();
			return ss.str();
		}
	};

	class MouseButtonReleasedEvent :public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const int mouseButtonCode)
			: MouseButtonEvent(mouseButtonCode) {
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: " << GetMouseButtonCode();
			return ss.str();
		}
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float deltaX, const float deltaY)
			: mDeltaX(deltaX)
			, mDeltaY(deltaY) {
		}

		float GetDeltaX() const { return mDeltaX; }
		float GetDeltaY() const { return mDeltaY; }

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled: " << mDeltaX<< "," << mDeltaY;
			return ss.str();
		};
	private:
		float mDeltaX;
		float mDeltaY;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float positionX, const float positionY)
			: mPositionX(positionX)
			, mPositionY(positionY) {
		}

		float GetPositionX() const { return mPositionX; }
		float GetPositionY() const { return mPositionY; }

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved: " << mPositionX << "," << mPositionY;
			return ss.str();
		};

	private:
		float mPositionX;
		float mPositionY;
	};
}
