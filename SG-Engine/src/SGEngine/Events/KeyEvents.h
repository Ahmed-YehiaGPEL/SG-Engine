#pragma once
#include "Event.h"

namespace SGEngine
{
	class SGE_API KeyEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

		int GetKeyCode() const { return mKeyCode; }
	protected:
		KeyEvent(const int keyCode)
			: mKeyCode(keyCode) {
		}
	private:
		int mKeyCode;
	};

	class SGE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keyCode, const int pressCount)
			: KeyEvent(keyCode)
			, mPressCount(pressCount) {
		}
		
		EVENT_CLASS_TYPE(KeyPressed);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

		int GetPressCount() const { return mPressCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed: " << GetKeyCode() << ", Repeat: " << mPressCount;
			return ss.str();
		}

	private:
		int mPressCount;
	};

	class SGE_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(const int keyCode)
			: KeyEvent(keyCode) {
		}
		
		EVENT_CLASS_TYPE(KeyPressed);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released: " << GetKeyCode();
			return ss.str();
		}

	};

}