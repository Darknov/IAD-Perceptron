#pragma once
#include <vector>
#include "NeuronLayer.h"
#include "LayerManager.h"

enum NetworkCreationMode
{
	CreateNew,
	LoadFromFile
};

class NeuralNetwork
{
public:
	bool useBias;
	int numberOfLayers;
	LayerManager layerManager;
	std::vector<NeuronLayer> layers;

	NeuralNetwork();
	NeuralNetwork(int numberOfLayers, int howMuchNeuronsInEachLayer[]);

	void learningMode();
	void testingMode();





};

