#include "LayerOfNeurons.h"
#include "Debug.h"

LayerOfNeurons::LayerOfNeurons(std::vector<Neuron> neuronz)
{
	this->neurons = neuronz;
}

void LayerOfNeurons::addNeuron(Neuron n)
{
	neurons.push_back(n);
}


Neuron LayerOfNeurons::getNeuron(int index)
{
	return neurons[index];
}

Neuron LayerOfNeurons::operator[](int i)
{
	return neurons[i];
}
