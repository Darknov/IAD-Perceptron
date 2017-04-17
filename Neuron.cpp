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
