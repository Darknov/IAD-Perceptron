#pragma once
#include <vector>
#include "NeuronLayer.h"
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
	int numberOfLayers;
	LayerManager layerManager;
	std::vector<NeuronLayer> layers;

	NeuralNetwork();
	NeuralNetwork(int numberOfLayers, int howMuchNeuronsInEachLayer[]);

	void learningMode();
	void testingMode();





};

