#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
	layers = layerManager.loadLayersFromFile();
}

NeuralNetwork::NeuralNetwork(int numberOfLayers, int howMuchNeuronsInEachLayer[])
{

	for (int i = 0; i < numberOfLayers; i++)
	{
		NeuronLayer layer(howMuchNeuronsInEachLayer[i]);
			layers.push_back(layer);
	}
}


