#pragma once

#include "Neuron.h"
class LayerOfNeurons
{
public:
	std::vector<Neuron> neurons;
	LayerOfNeurons(std::vector<Neuron> neuronz);

	void addNeuron(Neuron n);
	Neuron getNeuron(int index);
	Neuron operator[](int i);

};

