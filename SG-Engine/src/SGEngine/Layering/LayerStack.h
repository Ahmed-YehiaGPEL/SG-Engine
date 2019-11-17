#pragma once
#include "Core.h"
#include "vector"

namespace SGEngine
{
	class Layer;

	class SGE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		auto begin() const { return mLayers.begin(); }
		auto end() const { return mLayers.end(); }
	private:
		std::vector<Layer*> mLayers;
		std::vector<Layer*>::iterator mLayerInsertIterator;
	};
}
