#include "NeuralLayer.h"

NeuralLayer::NeuralLayer() {}; // nie jest to najładniejsza opcja, ale nie ma czasu żeby szukać jak to ładnie zrobić.

NeuralLayer::NeuralLayer(std::vector<Neuron> neurons)
{
	this->neurons = neurons;
}

void NeuralLayer::addNeuron(Neuron& n)
{
	neurons.push_back(n);
}

void NeuralLayer::setBias(Neuron& bias)
{
	this->bias = bias;
}

void NeuralLayer::setBiasPermissions(bool can)
{
	useBias = can;
}