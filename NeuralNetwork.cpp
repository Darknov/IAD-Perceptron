#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<LayerOfNeurons> layers)
{
	this->layers = layers;
}

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



