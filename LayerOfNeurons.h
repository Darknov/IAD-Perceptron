#pragma once

#include "Neuron.h"
class LayerOfNeurons
{
public:
	std::vector<Neuron> neurons;

	void addNeuron(Neuron n);
	Neuron getNeuron(int index);
	Neuron operator[](int i);

};

