#include "NeuralNetwork.h"
#include "Neuron.h"
#include <exception>
#include <fstream>
#include <iostream>

void NeuralNetwork::buildNetwork(std::vector<int>& howMuchNeuronsInEachLayer, Neuron sampleNeuron)
{
	for (int i = 0; i<howMuchNeuronsInEachLayer.size(); i++)
		for (int j = 0; j < howMuchNeuronsInEachLayer[i]; j++)
			layers[i].addNeuron(sampleNeuron);
}

NeuralNetwork::NeuralNetwork(std::string filePath)
{
	std::ifstream inputFileStream;
	inputFileStream.open(filePath);

	int learnSpeed;
		inputFileStream >> learnSpeed;

	int topologySize;
		inputFileStream >> topologySize;

	std::vector<int> topology;

	for (int i = 0; i < topologySize; i++)
	{
		int buffer;
		inputFileStream >> buffer;
		topology.push_back(buffer);
	}

	std::vector<double> weightsBuffer;

	while (inputFileStream.good())
	{
		for (int k = 0; k < topology.size(); k++)
		{
			NeuralLayer layer;

				for (int j = 0; j < topology[k]; j++)
				{
					weightsBuffer.clear();

					int numberOfWeights;
					inputFileStream >> numberOfWeights;

					for (int i = 0; i < numberOfWeights; i++)
					{
						double w;
						inputFileStream >> w;
						weightsBuffer.push_back(w);
					}

					Neuron n(weightsBuffer, learnSpeed);
					layer.addNeuron(n);
				}

			layers.push_back(layer);
		}
	}


}



NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer)
{
	Neuron n;
	buildNetwork(howMuchNeuronsInEachLayer, n);
}

NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, std::vector<double> startingWeights, double learnSpeed)
{
	Neuron n(startingWeights, learnSpeed);
	buildNetwork(howMuchNeuronsInEachLayer, n);
}

NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, std::vector<double> startingWeights, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative)
{
	Neuron n(startingWeights, learnSpeed, transferFunction, transferFunctionDerivative);
	buildNetwork(howMuchNeuronsInEachLayer, n);
}

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

std::vector<double> NeuralNetwork::getOutput()
{
	return this->output;
}

double NeuralNetwork::getError()
{
	return error;
}

void NeuralNetwork::propagateForward()
{
	for (int i = 0; i < layers.size() - 1; i++)
	{
		std::vector<double> currentLayerOutputs;

		NeuralLayer& currentLayer = layers[i];
		NeuralLayer& nextLayer = layers[i+1];

		for (int j=0; j<currentLayer.getSize(); j++)
		{
			Neuron currentNeuron = currentLayer.getNeuron(j);
			double currentNeuronOutput = currentNeuron.getOutput();
			currentLayerOutputs.push_back(currentNeuronOutput);
		}

		for (int k = 0; k < nextLayer.getSize(); k++)
		{
			Neuron currentNeuron = nextLayer.getNeuron(k);
			currentNeuron.setInput(currentLayerOutputs);
		}

	}
}


void NeuralNetwork::displayNetwork()
{
	int i = 0;

	for (NeuralLayer l : layers)
	{
		std::cout << "Warstwa nr " << i << ": " << std::endl;
		std::cout << "Liczba neuronow: " << l.getSize() << std::endl;
		std::cout << "Wagi: " << std::endl;
		std::vector<double> W;

		for (int j = 0; j < l.getSize(); j++)
		{
			W.clear();
			W = l.getNeuron(i).getWeights();

			for (int k = 0; k < W.size(); k++)
			{
				std::cout << " " << W[i] << " " << std::endl;
			}

		}

		i++;
	}

}