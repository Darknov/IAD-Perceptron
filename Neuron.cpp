#include "Neuron.h"



Neuron::Neuron()
{
}

void Neuron::setInput(std::vector<double> X)
{
	this->X = X;
}

void Neuron::setInput(double x)
{
	X.push_back(x);
}

void Neuron::setWeights(std::vector<double> W)
{
	this->W = W;
}

std::vector<double> Neuron::getWeights()
{
	return W;
}
