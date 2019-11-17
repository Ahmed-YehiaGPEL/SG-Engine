#include "sgepch.h"
#include "LayerStack.h"
#include "Layer.h"

namespace SGEngine
{
	LayerStack::LayerStack()
		: mLayerInsertIterator(mLayers.begin()) {
	}

	LayerStack::~LayerStack()
	{
		for (auto* layer : mLayers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		mLayerInsertIterator = mLayers.emplace(mLayerInsertIterator, layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		const auto layerIterator = std::find(mLayers.begin(), mLayers.end(), layer);
		if (layerIterator != mLayers.end())
		{
			mLayers.erase(layerIterator);
			--mLayerInsertIterator;
		}
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		mLayers.emplace_back(layer);
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		const auto layerIterator = std::find(mLayers.begin(), mLayers.end(), layer);
		if (layerIterator != mLayers.end())
		{
			mLayers.erase(layerIterator);
			--mLayerInsertIterator;
		}
	}
}
