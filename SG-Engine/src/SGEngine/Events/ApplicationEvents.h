#pragma once
#include "Event.h"
#include <sstream>

namespace SGEngine
{
	class SGE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(const int width, const int height)
			: mWidth(width)
			, mHeight(height) {

		}
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);

		int GetWidth() const { return mWidth; }
		int GetHeight() const { return mHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resized: " << mWidth << "," << mHeight;
			return ss.str();
		}
	private:
		int mWidth, mHeight;
	};

	class SGE_API WindowCloseEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
	};

	class SGE_API WindowFocusEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
	};

	class SGE_API WindowLostFocus : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowLostFocus);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
	};

	class SGE_API WindowMoved : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowMoved);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
	};

	class SGE_API AppUpdateEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
	};

	class SGE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent(const float deltaTime)
			:mDeltaTime(deltaTime) {

		}
		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);

		float GetDeltaTime() const { return mDeltaTime; }
		
	private:
		float mDeltaTime;
	};

	class SGE_API AppRenderEvent : public Event
	{
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
	};
}

