#pragma once

#include "Neuron.h"
class NeuronLayer
{
public:
	std::vector<Neuron> neurons;

	NeuronLayer(int numberOfNeurons);
};

