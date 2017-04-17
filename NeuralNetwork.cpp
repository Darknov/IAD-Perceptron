#include "NeuralNetwork.h"
#include <exception>

void NeuralNetwork::setBias(bool exists)
{
	for (NeuralLayer l : layers)
		l.setBiasPermissions(exists);
}

void NeuralNetwork::setInput(std::vector<double>& input)
{
	int i = 0;
	for (double x : input)
	{
		layers[0].getNeuron(i).setInput(x);
		i++;
	}
}