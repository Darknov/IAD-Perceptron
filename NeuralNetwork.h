#pragma once
#include <vector>
#include "NeuronLayer.h"
#include "LayerManager.h"

class NeuralNetwork
{
public:
	bool useBias;
	LayerManager manager;

	NeuralNetwork();
	std::vector<NeuronLayer> layers;

	void learningMode();
	void testingMode();





};

