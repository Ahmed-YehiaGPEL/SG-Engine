#pragma once
#include "Core.h"

namespace SGEngine
{
	class Event;

	class SGE_API Layer
	{
	public:
		explicit Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;
		virtual void OnAttach() {}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		std::string GetName() const { return mDebugName; }
	protected:
		std::string mDebugName;
	};
}
