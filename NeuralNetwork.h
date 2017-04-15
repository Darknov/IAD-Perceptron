#pragma once
#include <vector>
#include "LayerOfNeurons.h"
#include "LayerManager.h"

enum NetworkCreationMode
{
	CreateNew = 0,
	LoadFromFile = 1
};

class NeuralNetwork
{
public:
	bool useBias;
	LayerManager layerManager;
	std::vector<LayerOfNeurons> layers;

	void loadLayersFromFile();

	LayerOfNeurons getLayer(int index);
	void addLayer(LayerOfNeurons layer);
	int getNumberOfLayers();

};

