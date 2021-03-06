#include "NeuralNetwork.h"
#include "Neuron.h"
#include "Random.h"
#include <exception>
#include <fstream>
#include <iostream>

void NeuralNetwork::buildNetwork(std::vector<int>& howMuchNeuronsInEachLayer)
{
	std::vector<double> randomWeights = { 1 };
	int howMuchNeuronsInPreviousLayer = 1;
	for (int i = 0; i < howMuchNeuronsInEachLayer.size(); i++)
	{
		for (int j = 0; j < howMuchNeuronsInEachLayer[i]; j++)
		{
			randomWeights = generateRandomWeights(howMuchNeuronsInPreviousLayer);
			Neuron sampleNeuron(randomWeights, learnSpeed);
			layers[i].addNeuron(sampleNeuron);
		}

		howMuchNeuronsInPreviousLayer = layers[i].getSize();
	}
		

}

std::vector<double> NeuralNetwork::generateRandomWeights(int howMuchWeightsYouWish)
{
	Random lotto;
	std::vector<double> output;
	for (int i = 0; i < howMuchWeightsYouWish; i++)
		output.push_back(lotto.nextDoubleIncludingTop(-0.5, 0.5));
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

	inputFileStream.close();

}



NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer)
{
	Neuron n;
	buildNetwork(howMuchNeuronsInEachLayer, n);
	learnSpeed = 0.1;
}

NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, double learnSpeed)
{
	buildNetwork(howMuchNeuronsInEachLayer);
	this->learnSpeed = learnSpeed;
}

NeuralNetwork::NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative)
{
	buildNetwork(howMuchNeuronsInEachLayer);
	this->learnSpeed = learnSpeed;
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

void NeuralNetwork::backwardErrorPropagation(std::vector<double> &values)
{
	NeuralLayer &lastLayer = layers[layers.size() - 1];
	error = 0.0;

	int biasBufor = 0;

	if (lastLayer.useBias)
	{
		biasBufor = 1;
	}

	for (int i = 0; i <lastLayer.getSize() - biasBufor; i++)
	{
		double diff = values[i] - lastLayer.getNeuron(i).getOutput();
		error = error + diff*diff;
	}
	error = error / 2;

	if (isLearning)
	{
		// metoda gradientu prostego

		// obliczanie gradientu dla warstwy wyjsciowej

		for (int i = 0; i < lastLayer.getSize(); i++)
		{
			lastLayer.getNeuron(i).calcutaleOutputGradient(values[i]);
		}

		// obliczanie gradientu dla pozostałych warstw(bez wejsciowej bo nie przetwarza)
		for (int i = layers.size() - 2; i > 0; i--)
		{
			for (int j = 0; j < layers[i].getSize(); j++)
			{
				layers[i].getNeuron(j).calcutaleHiddenGradient(
					layers[i + 1].getGradients(),
					layers[i + 1].getWeightsOnInput(j));
			}
		}

		for (int i = layers.size() - 1; i > 0; i--)
		{
			for (int j = 0; j < layers[i].getSize(); i++)
			{
				layers[i].getNeuron(j).updateWeights(isMomentumRelevant);
			}
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

void NeuralNetwork::saveToFile(std::string filePath)
{
	std::ofstream outputFileStream;
	outputFileStream.open(filePath);

	std::vector<int> topology;

	for (NeuralLayer l : layers)
		topology.push_back(l.getSize());

	outputFileStream << learnSpeed
					 << topology.size();

		for (int i = 0; i < topology.size(); i++)
			outputFileStream << topology[i];

		int numberOfWeights = 1;
		for (NeuralLayer l : layers)
		{
			outputFileStream << numberOfWeights;

			for (int j = 0; j < l.getSize(); j++)
			{
				for (int k = 0; k < l.getNeuron(j).getWeights().size(); k++)
				{
					outputFileStream << l.getNeuron(j).getWeights()[k];
				}
			}

		}

	outputFileStream.close();
}

void NeuralNetwork::setLearning(bool shouldNetworkLearn)
{
	isLearning = shouldNetworkLearn;
}

void NeuralNetwork::setIfIsMomentumRelevant(bool isRelevant)
{
	isMomentumRelevant = isRelevant;
}