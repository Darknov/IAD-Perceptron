#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork()
{
}

void NeuralNetwork::setBias(bool exists)
{
	for (NeuralLayer l : layers)
		l.setBiasPermissions(exists);
}