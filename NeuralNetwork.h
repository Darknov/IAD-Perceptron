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
	NeuralNetwork();
	NeuralNetwork(std::vector<int>& howMuchNeuronsInEachLayer);

	void setBias(bool yep);

	void setInput(std::vector<double>& input);
	void propagateForward();

	void backwardErrorPropagation(); // z tego można zrobić z 5 metod

	std::vector<double> getOutput();
	double getError();

};

