#pragma once

#include <vector>
#include <cmath>

typedef double(*ActivationFunction)(double);
#define variant 3

class Neuron
{
public:

	std::vector<double> X;
	std::vector<double> W;
	ActivationFunction activationFunction;
	double learnSpeed;

	Neuron();
	Neuron(std::vector<double> W, double learnSpeed);
	void setActivationFunction(ActivationFunction function); // just assign appropriate function here. By default It'll be sigmoidal function.
	double getOutput();
	void setInput(std::vector<double> X);
	void updateWeights(int exp, int res, std::vector<double> X);

};


