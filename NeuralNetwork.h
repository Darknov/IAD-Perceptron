#pragma once
#include <vector>
#include "NeuralLayer.h"

class NeuralNetwork
{
private:
	std::vector<NeuralLayer> layers;
	std::vector<double> input;
	std::vector<double> output;
	double error;

public:
	//NeuralNetwork(); // tu miało być wczytywanie z pliku, ale byłoby to strasznie nieintuicyjne.
	NeuralNetwork(std::string filePath);
	NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer);
	NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, std::vector<double> startingWeights, double learnSpeed);
	NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer, std::vector<double> startingWeights, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative);

	void setBias(bool exists);

	void setInput(std::vector<double>& input);
	void propagateForward();

	void backwardErrorPropagation(); 

	std::vector<double> getOutput();

	double getError();

private:

	void buildNetwork(std::vector<int>& howMuchNeuronsInEachLayer, Neuron sampleNeuron);

};

