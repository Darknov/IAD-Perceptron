#include "LayerOfNeurons.h"
#include "Debug.h"


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
