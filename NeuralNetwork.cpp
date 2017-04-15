#include "NeuralNetwork.h"

LayerOfNeurons NeuralNetwork::getLayer(int index)
{
	return layers[index];
}

void NeuralNetwork::addLayer(LayerOfNeurons layer)
{
	layers.push_back(layer);
}

int NeuralNetwork::getNumberOfLayers()
{
	return layers.size();
}



