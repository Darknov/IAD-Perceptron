#include "Neuron.h"

double sigmoid(double z)
{
	return 1.0 / (1.0 + pow(2.72, -1 * z));
}

double sigmoidDerivative(double z)
{
	return pow(2.72, z) / ((2.72 + 1)*(2.72 + 1));
}

Neuron::Neuron()
{
	for (int i = 0; i < 2; i++)
	{
		W[i] = 1;
		learnSpeed = 0.1;
		setFunctions(sigmoid, sigmoidDerivative);
	}
}

Neuron::Neuron(std::vector<double> W, double learnSpeed)
{
	this->W = W;
	this->learnSpeed = learnSpeed;
	setFunctions(sigmoid, sigmoidDerivative);
}

Neuron::Neuron(std::vector<double> W, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative)
{
	this->W = W;
	this->learnSpeed = learnSpeed;
	setFunctions(transferFunction, transferFunctionDerivative);
}

void Neuron::setInput(std::vector<double> X)
{
	this->X = X;
}

void Neuron::setInput(double x)
{
	X.push_back(x);
}

void Neuron::setWeights(std::vector<double> W)
{
	this->W = W;
}

std::vector<double> Neuron::getWeights()
{
	return W;
}

double Neuron::getOutput()
{
	double sum = 0;
	
		for (int i = 0; i < W.size(); i++)
		{
			sum += X[i] * W[i];
		}
	
		return transferFunction(sum);
}